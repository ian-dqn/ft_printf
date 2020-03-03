/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:51:47 by iaduquen          #+#    #+#             */
/*   Updated: 2019/12/16 17:40:43 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		size;
	char		*str;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	if (len > size)
		len = size;
	if (start > size)
		len = 0;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < size)
	{
		while (i < len && s[start])
			str[i++] = s[start++];
	}
	str[i] = 0;
	return (str);
}
