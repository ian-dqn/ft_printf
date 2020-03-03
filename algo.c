/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:39:47 by iaduquen          #+#    #+#             */
/*   Updated: 2020/03/02 15:24:51 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		null_nb(int size)
{
	int	ret;

	ret = 0;
	while (size-- >= 0)
	{
		write(1, " ", 1);
		ret++;
	}
	return (ret);
}

int		ft_null_p(t_data *data)
{
	int	len;
	int	ret;

	len = 2;
	ret = 2;
	while (data->size-- > len)
		ret += write(1, " ", 1);
	write(1, "0x", 2);
	return (ret);
}

int		null_str(va_list ap, t_data *data)
{
	int ret;

	ret = 0;
	(data->preci < 6 && data->preci > -1 ?
		data->size -= data->preci : (data->size -= 6));
	while (!data->flag_m && data->size-- > 0)
		(data->flag_0 ? (ret += write(1, "0", 1)) : (ret += write(1, " ", 1)));
	if (data->preci < 6 && data->preci > -1)
		ret += write(1, "(null)", data->preci);
	else
		ret += write(1, "(null)", 6);
	while (data->size-- > 0)
		write(1, " ", 1) && ret++;
	return (ret);
}

int		ft_int_flag(va_list ap, t_data *data, long long nb)
{
	int ret;

	ret = 0;
	if (data->flag_0 && !data->flag_p)
	{
		ft_compar("id", data->c) && nb < 0 && write(1, "-", 1) && (nb *= -1);
		while (!data->flag_m && data->size-- > 0)
			ret += write(1, "0", 1);
	}
	while (!data->flag_m && data->size-- > 0)
		ret += write(1, " ", 1);
	ft_compar("id", data->c) && nb < 0 && write(1, "-", 1) && (nb *= -1);
	while (data->preci-- > 0 ||
			(data->flag_0 && !data->flag_m && data->size-- > 0))
		ret += write(1, "0", 1);
	if (data->flag_m)
	{
		ft_pprint(nb, data->c);
		while (data->size-- > 0)
			(data->flag_0 ? (ret += write(1, "0", 1)) :
				(ret += write(1, " ", 1)));
	}
	else
		ft_pprint(nb, data->c);
	return (ret);
}

void	ft_pprint(long unsigned int nb, char c)
{
	if (ft_compar("id", c))
		ft_putnbr_fd(nb, 1);
	else if (ft_compar("xX", c))
		(c == 'x' ? (ft_putnbr_hex(nb, 'x')) : (ft_putnbr_hex(nb, 'X')));
	else if (c == 'c')
		write(1, &nb, 1);
	else if (c == 'u')
		ft_uputnbr(nb);
	else if (c == '%')
		write(1, "%", 1);
}
