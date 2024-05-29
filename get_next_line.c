/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:03:52 by marvin            #+#    #+#             */
/*   Updated: 2024/04/24 01:03:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd); //Fonction principale
char	*get_dirty_line(int fd, char *dirty_line);

//Fonction principale
char	*get_next_line(int fd)
{
	static char	*dirty_line;
	char	*line;
	ssize_t	read_value;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) //Retourne NULL en cas d'erreurs
		return (NULL);
	dirty_line = get_dirty_line(fd, dirty_line); //Lis le fd par bloc de BUFFER_SIZE jusqu'au bloc contenant \n ou \0
	if (!dirty_line) //Retourne NULL en cas d'erreur de récupération de la ligne
		return (NULL);
	line = clean_line(dirty_line); //Nettoie la ligne récupérée
	dirty_line = start_next_line(dirty_line); //Prépare la ligne pour le prochain appel
	return (line); //Retourne la ligne nettoyée
	
}

char	*get_dirty_line(int fd, char *dirty_line)
{
	char	*buffer;
	ssize_t	bytes_read;
	
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!dirty_line)
	{
		dirty_line = (char *)malloc(1 * sizeof(char));
		dirty_line[0] = '\0';
	}
	while(1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		dirty_line = clean_join(dirty_line, buffer);
		if (is_eol(buffer))
		{
			free(buffer);
			return (dirty_line);
		}
	}
}

//clean_join()


/*
//MAIN
int	main(void)
{
	int		fd;

	fd = open("tests_read.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}
*/