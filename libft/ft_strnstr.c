/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcalle-m <dcalle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:20:32 by dcalle-m          #+#    #+#             */
/*   Updated: 2023/09/21 15:08:33 by dcalle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*str;

	i = 0;
	str = (char *)haystack;
	if (needle[i] == '\0')
		return (str);
	while (str[i] != '\0' && i < len)
	{
		k = i;
		j = 0;
		while (str[k] == needle[j] && k < len)
		{
			if (needle[j + 1] == '\0')
				return (&str[i]);
			k++;
			j++;
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str[8] = "Daniela";
// 	char	needle[4] = "iel";

// 	printf("%s\n", ft_strnstr(str, needle, 8));
// }
