/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:51:20 by iaduquen          #+#    #+#             */
/*   Updated: 2020/03/02 15:51:22 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intcount(long long n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	return (++count);
}
