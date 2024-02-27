/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:48:28 by dcalle-m          #+#    #+#             */
/*   Updated: 2024/02/24 13:13:51 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

void	ft_free(void *ptr);
size_t	ft_strlen(char *str);
void	ft_memcpy(char *dst, char *src, size_t len);
ssize_t	ft_strchr(char *str, char c);

char	*get_next_line(int fd);

#endif