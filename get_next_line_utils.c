/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:25:57 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/01 20:02:58 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Ajoute le bloc à la liste d'attente.
	Renvoie 1 en cas de succès.
	Renvoie 0 en cas d'erreur d'allocation.
*/
int	add_to_list(int bytes_read, char *buffer, t_list **list)
{
	int		i;
	t_list	*node;
	t_list	*cursor;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = (char *)malloc((bytes_read + 1) * sizeof(char));
	if (!node->content)
		return (0);
	i = -1;
	while (++i < bytes_read)
		node->content[i] = buffer[i];
	buffer[i] = '\0';
	if (!*list)
		*list = node;
	else
	{
		cursor = *list;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = node;
	}
	return (1);
}

/*
	Ajoute le contenu de la réserve au début de la liste d'attente.
	Renvoie 1 si l'entièreté de la ligne suivante est déjà contenu dans la
		réserve ou si une erreur se produit.
	Renvoie 0 si tout se passe correctement.
*/
int	stash_to_list(char	*stash, t_list **list)
{
	t_list	*node;
	int		i;

	if (!stash)
		return (ALRIGHT);
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (MALLOC_ERROR);
	node->content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!node->content)
	{
		free(node);
		return (MALLOC_ERROR);
	}
	i = -1;
	while (stash[++i])
		node->content[i] = stash[i];
	node->next = NULL;
	*list = node;
	return (ALRIGHT);
}
