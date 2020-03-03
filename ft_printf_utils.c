/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 08:36:03 by iaduquen          #+#    #+#             */
/*   Updated: 2020/02/29 17:47:49 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_count(long long n, char c)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	if (ft_compar("c%", c))
		n = 0;
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	return (++count);
}

int		ft_count_hexa(unsigned int n, unsigned int base_size)
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

int		ft_putnbr_hex(unsigned int n, char c)
{
	char	*base;
	int		len;

	if (!(base = (char *)malloc(17)))
		return (0);
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = ft_strlen(base);
	if (n >= len)
	{
		ft_putnbr_hex((n / len), c);
		ft_putnbr_hex((n % len), c);
	}
	else
		write(1, &base[n], 1);
	return (1);
}

int		ft_matoi(char **s)
{
	int		res;
	char	*str;
	int		i;

	i = 0;
	str = *s;
	res = 0;
	while (*str && ft_isdigit(*str))
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	*s = str;
	return (res);
}

void	ft_uputnbr(long long n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_uputnbr(n / 10);
		ft_uputnbr(n % 10);
	}
	else
		ft_putchar_fd(n + 48, 1);
}
