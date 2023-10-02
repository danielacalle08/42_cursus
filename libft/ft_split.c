/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:14:38 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/10/02 16:26:09 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

char	*ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	**ft_fill(char const *s, char c, char **array)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	end = 0;
	while (i < ft_count(s, c))
	{
		start = end;
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		array[i] = ft_substr(s, start, (end - start));
		if (!array[i])
			return (ft_free(array));
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = ft_fill(s, c, array);
	if (!array)
		return (NULL);
	return (array);
}
