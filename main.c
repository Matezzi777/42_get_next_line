/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:42:53 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/15 17:36:25 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

#define TRUE 1

int	main(int argc, char **argv)
{
	int		i;
	int		keep_going;
	int		fd;
	int		line_count;
	int		fds[argc - 1];
	char	*line;
	char	*lines[argc - 1];

	if (argc < 2)
	{
		return (printf("Wrong number of arguments. (at least 1 expected)\n"
			"	Use : ./a.out <path_to_file>\n"));
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (printf("Unable to open %s.\n", argv[1]));
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
	else
	{
		i = 0;
		while (++i < argc)
		{
			fds[i - 1] = open(argv[i], O_RDONLY);
			if (fds[i - 1] == -1)
				return (printf("Unable to open %d file (%s).\n", i, argv[i]));
		}
		keep_going = 1;
		line_count = 1;
		while (keep_going)
		{
			i = 0;
			while (++i < argc)
				lines[i - 1] = get_next_line(fds[i - 1]);
			keep_going = 0;
			i = 0;
			while (++i < argc)
				if (lines[i - 1])
					keep_going = 1;
			printf("\nLINE %d :\n", line_count);
			i = 0;
			while (++i < argc)
			{
				if (lines[i - 1])
					printf("%d : %s", fds[i - 1], lines[i - 1]);
				else
					printf("%d : NULL\n", fds[i - 1]);
			}
			printf("\n");
			i = 0;
			while (++i < argc)
				if (lines[i - 1])
					free(lines[i - 1]);
		}
		i = 0;
		while (++i < argc)
			close(fds[i - 1]);
	}
}
