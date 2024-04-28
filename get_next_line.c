/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:03:52 by marvin            #+#    #+#             */
/*   Updated: 2024/04/24 01:03:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <=0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

int	main(void)
{
	// printf("Test :\n");
	// if (BUFFER_SIZE > 0)
	// 	printf("BUFFER_SIZE = %d", BUFFER_SIZE);
	// else
	// 	printf("BUFFER_SIZE = %d\nINVALID BUFFER SIZE", BUFFER_SIZE);
	return (0);
}