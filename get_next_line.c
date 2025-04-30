/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:26:00 by maxmart2          #+#    #+#             */
/*   Updated: 2025/04/30 11:38:34 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*
	Fonction principale
*/
char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;
	int				readed;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	line = NULL;
	readed = 1;
	read_and_stash(fd, &stash, &readed);
	if (stash == NULL)
		return (NULL);
	return (line);
}

/*
	Uses read() to add characters to the stash
*/
void	read_and_stash(int fd, t_list **stash, int *readed)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	while (!found_newline(*stash) && *readed != 0)
	{
		*readed = read(fd, buffer, BUFFER_SIZE);
		if ((*stash == NULL && *readed == 0) || (readed == -1))
		{
			free(buffer);
			return ;
		}
		buffer[*readed] = '\0';
	}
}

/*
	Adds the content of our buffer to the end of our stash
*/
void	add_to_stash()
{
	
}

/*
	Extracts all character from our stash and stores them in out line.
	Stopping after the first \n it encounters
*/
void	extract_line()
{
	
}

/*
	After extracting the line that was read, we don't need those characters anymore.
	This function clears the stash so only the characters that have to not been returned at
	the end of get_next_line() remain in our static stash.
*/
void	clean_stash()
{
	
}