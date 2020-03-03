/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:15:53 by iaduquen          #+#    #+#             */
/*   Updated: 2020/03/02 15:21:32 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		str_bloc(va_list ap, t_data *data, char *fmt)
{
	char	*s;
	int		ret;
	int		len;
	int		data_size;

	s = va_arg(ap, char *);
	if (!s)
		return (null_str(ap, data));
	len = ft_strlen(s);
	data->preci > -1 && data->preci < len && (len = data->preci);
	ret = len;
	while (!data->flag_m && data->size-- > len)
		(data->flag_0 ? (ret += write(1, "0", 1)) : (ret += write(1, " ", 1)));
	write(1, s, len);
	while (data->size-- > len)
		write(1, " ", 1) && ret++;
	return (ret);
}

int		ft_num_bloc(va_list ap, t_data *data, char *fmt)
{
	int	nb;
	int	nb_size;
	int	ret;

	if (ft_compar("idxXc", data->c))
		nb = va_arg(ap, int);
	else
		nb = '%';
	if (ft_compar("xX", data->c))
		nb_size = ft_hexacount(nb, 16);
	else
		nb_size = ft_count(nb, data->c);
	ret = nb_size;
	(data->size -= nb_size);
	(data->c != '%' ? (data->preci -= nb_size) : (data->preci = -1));
	(data->preci > 0 ? data->size -= data->preci : 0);
	if (nb < 0 && ft_compar("id", data->c))
		++ret && data->size--;
	if (nb == 0 && data->flag_p && data->preci == -1)
		return (null_nb(data->size));
	else if (data->size > 0 || data->preci >= 0)
		ret += ft_int_flag(ap, data, nb);
	else
		ft_pprint(nb, data->c);
	return (ret);
}

int		ft_unsigned_bloc(va_list ap, t_data *data)
{
	unsigned long	nb;
	int				nb_size;
	int				ret;

	nb = va_arg(ap, unsigned int);
	nb_size = ft_count(nb, data->c);
	ret = nb_size;
	(data->preci -= nb_size);
	(data->size -= nb_size);
	(data->preci > 0 ? data->size -= data->preci : 0);
	if (nb == 0 && data->flag_p && data->preci == -1)
		return (null_nb(data->size));
	else if (data->size > 0 || data->preci >= 0)
		ret += ft_int_flag(ap, data, nb);
	else
		ft_pprint(nb, data->c);
	return (ret);
}

int		ft_pourcent(va_list ap, t_data *data)
{
	int	ret;

	ret = 1;
	if (data->flag_m)
		write(1, "%", 1);
	while (data->size > 1)
	{
		if (data->flag_0)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
		data->size--;
	}
	if (!data->flag_m)
		write(1, "%", 1);
	return (ret);
}

int		ft_p(va_list ap, t_data *data)
{
	char					*str;
	long long unsigned int	nb;
	int						len;
	int						ret;

	str = va_arg(ap, char*);
	nb = (long long unsigned int)str;
	str = ft_utoa(nb);
	ret = ft_strlen(str) + 2;
	len = ft_strlen(str) + 2;
	if (data->preci == 0 && nb == 0)
		return (ft_null_p(data));
	(data->preci -= len);
	(data->size -= len);
	(data->preci > 0 ? data->size -= data->preci : 0);
	if (data->flag_m)
		ft_putdbstr("0x", str);
	if (data->size > 0 || data->preci >= 0)
		ret += ft_int_flag(ap, data, nb);
	if (!data->flag_m)
		ft_putdbstr("0x", str);
	free(str);
	return (ret);
}
