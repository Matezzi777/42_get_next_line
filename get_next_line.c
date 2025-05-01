/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:26:00 by maxmart2          #+#    #+#             */
/*   Updated: 2025/04/30 15:35:13 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*
	Fonction principale
*/
char	*get_next_line(int fd)
{
	int				readed;
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	line = NULL;
	readed = 1;
	read_and_stash(fd, &stash, &readed);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
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
		add_to_stash(stash, buffer);
	}
}

/*
	Adds the content of our buffer to the end of our stash
*/
void	add_to_stash(t_list **stash, char *buffer)
{
	t_list	*last;
	t_list	*node;

	last = ft_lst_get_last(stash);
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return ;
	node->content = ft_strdup(buffer);
	if (!node->content)
	{
		free(node);
		return ;
	}
	last->next = node;
	node->next = NULL;
}

/*
	Extracts all character from our stash and stores them in out line.
	Stopping after the first \n it encounters
*/
char	*extract_line(t_list **stash)
{
	int		bytes;
	int		i;
	t_list	*node;
	char	*line;

	line = (char *)malloc((get_line_length(stash) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (*stash)
	{
		i = 0;
		while ((*stash)->content[i])
		{
			line[bytes] = (*stash)->content[i];
			i++;
			bytes++;
		}
		stash = (*stash)->next;
	}
}

/*
	After extracting the line that was read, we don't need those characters anymore.
	This function clears the stash so only the characters that have to not been returned at
	the end of get_next_line() remain in our static stash.
*/
void	clean_stash(t_list **stash)
{
	t_list	*node;
	t_list	*next_node;
	int		len;
	char	*save;

	node = *stash;
	while (node->next)
	{
		next_node = node->next;
		free(node->content);
		free(node);
		node = next_node;
	}
	len = 0;
	while (node->content[len] && node->content[len] != '\n')
		len++;
	len = BUFFER_SIZE - len;
	if (len)
		
}
