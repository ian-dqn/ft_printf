/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:22:43 by iaduquen          #+#    #+#             */
/*   Updated: 2019/11/11 10:40:00 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	if (!src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
		while (len - i > 0)
		{
			dest[len - i - 1] = source[len - i - 1];
			i++;
		}
	return (dest);
}
