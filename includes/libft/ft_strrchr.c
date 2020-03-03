/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:25:39 by iaduquen          #+#    #+#             */
/*   Updated: 2019/11/06 17:31:50 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	i++;
	while (i != 0)
	{
		if (*str == c)
			return ((char *)str);
		i--;
		str--;
	}
	return (0);
}
