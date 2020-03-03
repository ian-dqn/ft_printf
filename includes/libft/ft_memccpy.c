/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:14:06 by iaduquen          #+#    #+#             */
/*   Updated: 2019/11/12 18:52:47 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	if (!src)
		return (NULL);
	str = (unsigned char*)src;
	str2 = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		str2[i] = str[i];
		if (str[i] == (unsigned char)c)
		{
			return (str2 + i + 1);
		}
		i++;
	}
	return (NULL);
}
