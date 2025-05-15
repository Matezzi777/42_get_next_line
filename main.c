/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:42:53 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/15 17:12:13 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

#define TRUE 1

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Wrong number of arguments. (1 expected)\n"
			"	Use : ./a.out <path_to_file>\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	i = 1;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("End of file reached (%d lines read).\n", i - 1);
			break ;
		}
		printf("LINE %d : \"%s\"\n", i, line);
		free(line);
		i++;
	}
}
