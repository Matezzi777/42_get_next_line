/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:26:07 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/01 20:06:10 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> //malloc(), free()
# include <unistd.h> //read()

# define TRUE 1
# define ALRIGHT 0
# define MALLOC_ERROR 1
# define ALREADY_CONTAINED 2

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
void	read_to_list(int fd, t_list **list);
char	*list_to_string(t_list **list);
char	*list_to_stash(t_list **list);
void	empty_list(t_list **list);
//get_next_line_utils.c
int		add_to_list(int bytes_read, char *buffer, t_list **list);
int		stash_to_list(char *stash, t_list **list);
char	*stash_to_string(char *stash);
char	*cat_and_free(char *line, char *bloc);
char	*clean_line(char *line);

#endif