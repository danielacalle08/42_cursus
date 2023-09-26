/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:13:35 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/09/26 17:43:58 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	start = 0;
	if (!set[start] || !s1[start])
		return (ft_strdup(s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (!s1[start])
		return (ft_strdup(&s1[start]));
	end = ft_strlen(s1) -1;
	while (ft_strchr(set, s1[end]))
		end--;
	res = malloc((end - start + 2) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < end - start + 1)
		res[i] = s1[start + i];
	res[i] = '\0';
	return (res);
}
