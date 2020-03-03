/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:27:14 by iaduquen          #+#    #+#             */
/*   Updated: 2019/11/07 17:30:58 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!haystack || len == 0)
		return (NULL);
	while (haystack[j] && j < len)
	{
		i = 0;
		while (haystack[j + i] == needle[i] && (i + j < len))
		{
			i++;
			if (needle[i] == 0)
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (NULL);
}
