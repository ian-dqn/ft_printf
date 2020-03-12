/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:51:38 by iaduquen          #+#    #+#             */
/*   Updated: 2020/03/02 15:51:40 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned int nb, char *base)
{
	char			*str;
	int				i;
	int				size;
	unsigned int	size_base;

	size_base = ft_strlen(base);
	size = ft_hexacount(nb, size_base);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size - 1;
	while (nb >= size_base)
	{
		str[i] = base[nb % size_base];
		nb /= size_base;
		i--;
	}
	str[i] = base[nb % size_base];
	str[size] = '\0';
	return (str);
}
