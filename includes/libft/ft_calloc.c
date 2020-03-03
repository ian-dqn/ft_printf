/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:15:04 by iaduquen          #+#    #+#             */
/*   Updated: 2019/12/13 16:22:42 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*alloc;
	size_t	i;

	i = 0;
	if (!(alloc = (malloc(size * count))))
		return (NULL);
	ft_bzero(alloc, size * count);
	return (alloc);
}
