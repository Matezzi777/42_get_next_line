/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:23:19 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/15 17:13:43 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h> //malloc(), free()
# include <unistd.h> //read()

//get_next_line.c
char	*get_next_line(int fd);
char	*ft_join_and_free(char *stash, char *buffer);
char	*ft_prepare_next_call(char *buffer);
char	*ft_line_from_stash(char *buffer);
char	*read_file(int fd, char *stash);
//get_next_line_utils.c
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);

#endif