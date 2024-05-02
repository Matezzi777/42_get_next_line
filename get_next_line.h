#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Tests
# include <stdio.h> //printf()
# include <fcntl.h> //open()
//Rendu
# include <unistd.h> //read() & write()
# include <stdlib.h> //malloc() & free()
# include <stddef.h>
// # include <sys/types.h>
// # include <sys/uio.h>

//get_next_line.c
char	*get_next_line(int fd);
char	*read_line(int fd, char *buffer, int buffer_length);

// get_next_line_utils.c
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif