/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:26:07 by maxmart2          #+#    #+#             */
/*   Updated: 2025/04/30 15:27:33 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> //malloc(), free()
# include <unistd.h> //read()

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

//get_next_line.c
char	*get_next_line(int fd);
void	read_and_stash(int fd, t_list **stash, int *readed);
void	add_to_stash();
char	*extract_line(t_list **stash);
void	clean_stash();
//get_next_line_utils.c
int		found_new_line(t_list **stash);
t_list	*ft_lst_get_last(t_list **stash);
void	generate_line();
void	free_stash();
int		get_line_length(t_list **stash);


#endif