/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:32:38 by iaduquen          #+#    #+#             */
/*   Updated: 2020/03/02 15:24:12 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_other(t_data *data)
{
	if (data->flag_m || data->flag_0 || data->flag_p || data->size)
		data->flag = 1;
	if ((data->flag_m && data->flag_0))
		data->flag_0 = 0;
	if (data->preci <= -1)
		data->flag_p = 0;
}

char	*ft_dot(va_list ap, t_data *data, char *fmt)
{
	int i;

	i = 0;
	data->preci = 0;
	if (*++fmt == '*')
	{
		data->preci = va_arg(ap, int);
		fmt++;
	}
	data->flag_p = 1;
	ft_isdigit(*fmt) && (data->preci = ft_matoi(&fmt));
	return (fmt);
}

char	*ft_gest_flag(va_list ap, t_data *data, char *fmt)
{
	int	nb;

	while (!ft_compar("cspdiuxX%", *fmt) && *fmt)
	{
		if (*fmt == '*')
		{
			nb = va_arg(ap, int);
			(nb < 0 ? data->flag_m = 1 && (nb *= -1) : 0);
			data->size = nb;
			fmt++;
		}
		else if (*fmt == '0' && *fmt++)
			data->flag_0 = 1;
		if (ft_isdigit(*fmt))
			data->size = ft_matoi(&fmt);
		else if (*fmt == '.')
			fmt = ft_dot(ap, data, fmt);
		else if (!ft_compar("cspdiuxX%", *fmt) && *fmt == '-' && *fmt++)
			data->flag_m = 1;
		if (!ft_verif(*fmt))
			return (NULL);
	}
	ft_other(data);
	return (fmt);
}

char	*ft_redirect(va_list ap, t_data *data, char *fmt, int *ret)
{
	int i;

	i = 0;
	if (!ft_compar("cspdiuxX%", fmt[i]))
		if (!(fmt = ft_gest_flag(ap, data, fmt)))
			return (NULL);
	(ft_verif(fmt[i]) ? data->c = fmt[i] : 0);
	if (ft_compar("dixXc", data->c))
		*ret += ft_num_bloc(ap, data, &fmt[i]);
	else if (data->c == 'u')
		*ret += ft_unsigned_bloc(ap, data);
	else if (data->c == 's')
		*ret += str_bloc(ap, data, &fmt[i]);
	else if (data->c == 'p')
		*ret += ft_p(ap, data);
	else if (data->c == '%')
		*ret += ft_pourcent(ap, data);
	else
	{
		free(data);
		return (NULL);
	}
	free(data);
	return (fmt + i);
}

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		ret;
	int		wr;
	t_data	data;

	ret = 0;
	wr = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && ft_verif(*++fmt))
		{
			if (!(fmt = ft_redirect(ap, init_struct(&data), fmt, &ret)))
				return (ret + wr);
		}
		else if (*fmt)
			wr += write(1, fmt, 1);
		else
			return (ret + wr);
		fmt++;
	}
	va_end(ap);
	return (ret + wr);
}
