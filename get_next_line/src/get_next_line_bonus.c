/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:48:13 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/12/05 13:48:04 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*join_line(char *line, char *buf)
{
	char	*new_line;
	size_t	line_len;
	size_t	buf_len;

	line_len = ft_strlen(line);
	buf_len = 0;
	while (buf[buf_len] != '\0' && buf[buf_len] != '\n')
		buf_len++;
	if (buf[buf_len] == '\n')
		buf_len += 1;
	new_line = (char *)malloc(sizeof(char) * (line_len + buf_len + 1));
	if (new_line == NULL)
		return (ft_free(line), NULL);
	ft_memcpy(new_line, line, line_len);
	ft_memcpy(new_line + line_len, buf, buf_len);
	new_line[line_len + buf_len] = '\0';
	return (ft_free(line), new_line);
}

static void	rest(char *buf)
{
	size_t	buf_len;
	size_t	rest_len;

	buf_len = 0;
	while (buf[buf_len] != '\0' && buf[buf_len] != '\n')
		buf_len++;
	if (buf[buf_len] == '\n')
	{
		rest_len = ft_strlen(buf + buf_len + 1);
		ft_memcpy(buf, buf + buf_len + 1, rest_len);
		buf[rest_len] = '\0';
	}
	else
		buf[0] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[4096][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = join_line(NULL, buf[fd]);
	if (line == NULL)
		return (NULL);
	while (ft_strchr(line, '\n') == -1)
	{
		bytes_read = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && ft_strlen(line) == 0))
			return (buf[fd][0] = '\0', ft_free(line), NULL);
		if (bytes_read == 0)
			break ;
		buf[fd][bytes_read] = '\0';
		line = join_line(line, buf[fd]);
		if (line == NULL)
			return (NULL);
	}
	return (rest(buf[fd]), line);
}
