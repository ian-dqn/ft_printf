/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:53:04 by iaduquen          #+#    #+#             */
/*   Updated: 2019/11/11 14:31:10 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strncat(char *dst, char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && j < n)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (dst);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	if (len_dst >= size)
		return (size + len_src);
	if (len_src < size - len_dst)
		ft_strncat(dst, (char *)src, len_src + 1);
	else
	{
		ft_strncat(dst, (char *)src, size - len_dst - 1);
		dst[size - 1] = '\0';
	}
	return (len_dst + len_src);
}
