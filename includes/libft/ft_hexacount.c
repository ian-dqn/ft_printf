/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexacount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:51:04 by iaduquen          #+#    #+#             */
/*   Updated: 2020/03/02 15:51:07 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hexacount(unsigned int n, unsigned int base_size)
{
	int i;

	i = 1;
	while (n >= base_size)
	{
		n /= base_size;
		i++;
	}
	if (i > 8)
		i = 8;
	return (i);
}
