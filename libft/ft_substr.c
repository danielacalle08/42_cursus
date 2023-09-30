/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:58:34 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/09/27 18:48:16 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start || s[i] == '\0')
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char	*s;
// 	size_t	len;

// 	len = -1;
// 	s = "hola";
// 	printf("LEN: %zu\n", len);
// 	printf("LEN + 1: %zu", len + 1);
// }
