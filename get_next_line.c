/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:26:00 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/02 13:25:03 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Fonction principale
*/
char	*get_next_line(int fd)
{
	static char	save[1024][BUFFER_SIZE];
	t_list		*list;
	char		*line;
	int			case_init;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 1 || read(fd, NULL, 0))
		return (NULL);
	case_init = stash_to_list(save[fd], &list);
	if (case_init == MALLOC_ERROR)
		return (NULL);
	if (case_init == ALREADY_CONTAINED)
		return (stash_to_string(save[fd]));
	read_to_list(fd, &list);
	line = list_to_string(&list);
	list_to_stash(&list, save[fd]);
	empty_list(&list);
	return (line);
}

/*
	Lis le fd et remplis la liste d'attente.
*/
void	read_to_list(int fd, t_list **list)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	int		i;

	while (TRUE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return ;
		if (!add_to_list(bytes_read, buffer, list))
			return ;
		if (bytes_read < BUFFER_SIZE)
			return ;
		i = -1;
		while (++i < BUFFER_SIZE)
			if (buffer[i] == '\n')
				return ;
	}
}

/*
	Convertit la ligne depuis le contenu de la liste d'attente et la retourne.
	Si la liste d'attente est vide, ou qu'une erreur arrive retourne NULL.
*/
char	*list_to_string(t_list **list)
{
	t_list	*cursor;
	char	*line;

	if (!list || !*list)
		return (NULL);
	line = NULL;
	cursor = *list;
	while (cursor)
	{
		line = cat_and_free(line, cursor->content);
		if (!line)
			return (NULL);
		cursor = cursor->next;
	}
	return (clean_line(line));
}

/*
	Retourne les caractères à mettre en réserve
		pour le prochain appel à get_next_line().
	Retourne NULL si rien à mettre en réserve.
*/
void	list_to_stash(t_list **list, char *stash)
{
	int		i;
	int		j;
	t_list	*cursor;

	if (!list || !*list)
		return ;
	cursor = *list;
	while (cursor->next)
		cursor = cursor->next;
	i = 0;
	while (cursor->content[i] && cursor->content[i] != '\n')
		i++;
	if (!cursor->content[i])
		return ;
	j = 0;
	while (cursor->content[++i])
		stash[j++] = cursor->content[i];
	if (j == 0)
		return ;
	stash[++j] = '\0';
}

/*
	Libère la mémoire allouée pour la liste d'attente.
*/
void	empty_list(t_list **list)
{
	t_list	*cursor;
	t_list	*next;

	if (!list || !*list)
		return ;
	cursor = *list;
	while (cursor)
	{
		if (cursor->content)
			free(cursor->content);
		next = cursor->next;
		free(cursor);
		cursor = next;
	}
}
