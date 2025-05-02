/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:25:57 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/02 13:26:48 by maxmart2         ###   ########.fr       */
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
	i = -1;
	while (stash[++i])
		if (stash[i] == '\n')
			return (ALREADY_CONTAINED);
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

/*
	Renvoie la ligne suivante depuis la réserve
	lorsqu'elle est déjà contenue en entièreté.
*/
char	*stash_to_string(char *stash)
{
	int		i;
	int		j;
	char	*line;

	line = clean_line(stash);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		stash = NULL;
	j = 0;
	while (stash[++i])
	{
		stash[j] = stash[i];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		stash[j] = '\0';
		j++;
	}
	return (line);
}

/*
	Concatène le bloc à la suite de la line.
	Free la line et retourne la nouvelle ligne créée pour la remplacer.
	Retourne NULL si une erreur se produit.
*/
char	*cat_and_free(char *line, char *bloc)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	if (!line)
		return (bloc);
	while (line[i])
		i++;
	j = 0;
	while (bloc[j])
		j++;
	new = (char *)malloc((i + j + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (line[++i])
		new[i] = line[i];
	j = -1;
	while (bloc[++j])
		new[i++] = bloc[j];
	new[i] = '\0';
	free(line);
	return (new);
}

/*
	Retire les caractères en trop à la fin de la ligne avant de la renvoyer.
*/
char	*clean_line(char *dirty_line)
{
	int		i;
	char	*clean_line;

	i = 0;
	while (dirty_line[i] && dirty_line[i] != '\n')
		i++;
	clean_line = (char *)malloc((i + 2) * sizeof(char));
	if (!clean_line)
		return (NULL);
	clean_line[i + 1] = '\0';
	while (i >= 0)
	{
		clean_line[i] = dirty_line[i];
		i--;
	}
	free(dirty_line);
	return (clean_line);
}
