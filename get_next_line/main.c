/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:49:02 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/12/05 13:21:19 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc < 2)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	i = 1;
	while (i <= 10)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%d: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (EXIT_SUCCESS);
}
