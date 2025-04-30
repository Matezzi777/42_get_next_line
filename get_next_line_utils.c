/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:25:57 by maxmart2          #+#    #+#             */
/*   Updated: 2025/04/30 11:54:12 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Looks for a newline character in the giver linked list.
		Returns the index of the '\n' character if found.
		Returns 0 if not found.
*/
int	found_newline(t_list **stash)
{
	t_list	*last_node;
	int	i;

	last_node = ft_lst_get_last(stash);
	i = -1;
	while (last_node->content[++i])
		if (last_node->content[i] == '\n')
			return (i);
	return (0);

}

/*
	Returns a pointer to the last node in our stash.
*/
t_list	*ft_lst_get_last(t_list **stash)
{
	t_list	*last;

	if (!stash || !*stash)
		return (NULL);
	last = *stash;
	while (last->next)
		last = last->next;
	return (last);
}

/*
	Calculates the number of chars in the current line, including the trailing \n if there is one
	and allocates memory accordingly.
*/
void	generate_line()
{

}

/*
	Frees the entire stash.
*/
void	free_stash()
{

}