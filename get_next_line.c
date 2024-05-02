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
char	*read_line(int fd, char *buffer, int buffer_length); //Récupère la ligne
char	*clean_line(char *line); //Nettoie la ligne
int		check_new_line(char *buffer); //Vérifie si la fin de la ligne est atteinte

//Fonction principale
char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;
	int		buffer_length;
	
	if (!BUFFER_SIZE)
		buffer_length = 5;
	else
		buffer_length = BUFFER_SIZE;
	buffer = (char *)malloc((buffer_length + 1) * sizeof(char));
	if (!buffer)
		return(NULL);
	line = read_line(fd, buffer, buffer_length); //Récupère la ligne
	free(buffer);
	return (line);
}

//Récupère la ligne
char	*read_line(int fd, char *buffer, int buffer_length)
{
	char	*line;
	ssize_t	bytes_read;
	int		new_line;

	line = ""; //Initialise la ligne
	while (1)
	{
		bytes_read = read(fd, buffer, buffer_length); //Lis dans le fichier
		buffer[buffer_length] = '\0';
		if (bytes_read == -1) //Si erreur de lecture
			return (NULL); //Retourne l'erreur
		else //Si lecture réussie
		{
			new_line = check_new_line(buffer);
			line = ft_strjoin(line, buffer); //Ajoute le contenu du buffer à la suite de la ligne
			if (bytes_read < buffer_length || new_line == 1) //Si le buffer n'est pas rempli ou que la fin de la ligne est atteint
				return (line);
				// return (clean_line(line)); //Nettoie la ligne et la retourne.
		}
	}
}

//Nettoie la ligne
// char	*clean_line(char *line);
// {

// }

//Vérifie si la fin de la ligne est atteinte
int		check_new_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//MAIN
int	main(void)
{
	int		fd;

	fd = open("tests_read.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}