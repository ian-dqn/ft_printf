/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:32:38 by iaduquen          #+#    #+#             */
/*   Updated: 2020/01/26 01:16:54 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
   int	ft_check_arg(va_list ap, int n)
   {
   check if arg == expected
 **if n == 1 : int,
 **if n == 2 : str,
 **if n == 3 : char,
 **if n == 4 ptr,

 **if '.', flag == 1;
 **if '-', flag == 2;
 **if '0', flag == 3;

 flag '0' is ignored when flag '-' is present

 int n;
 char *str;
 if (n == 1)
 if (!(va_arg(ap, int)))
 return (O);
 if (n == 2)
 if (!(va_arg(ap, char *)))
 return (O);
 if (n == 3)
 if (!(va_arg(ap, char)))
 return (O);
 if (n == 4)
 if (!(va_arg(ap, char)))

 }
 */

void	ft_str_flag(va_list ap, s_data *data, char *s)
{
	data->preci -= ft_strlen(s);
/*	if (data->flag_0)
		while (data->preci > 0)
			write(1, "0", 1);
	if (!data->flag)
		while (len-- > 0)
			write(1, " ", 1);*/
/*	if (data->flag_m)
	{
		while (data->preci-- > 0)
			write(1, &s, 1) && s++;
		while (data->size-- > 0)
			write(1, " ", 1);
	}
	else
*/		
		while (data->preci-- > 0)
			write(1, s, 1) && s++;
}

void ft_width(s_data *data, int len)
{
	/*
	 *prototype pour essayer de gerer preci && size
	 * */
	(data->preci -= len);
	(data->size -= len);
}

void	str_bloc(va_list ap, s_data *data, char *fmt)
{
	char	*s;
	int		i;
	int		len;

	s = va_arg(ap, char *);
	if ((len = ft_strlen(s)) > data->preci)
	{
		len = 0;
		while (data->preci-- > 0)
			write(1, &s[len++], 1);
	}
	else if (len > data->size || data->flag_p)
		ft_putstr(s);
	while (len < data->size--)
		write(1, " ", 1);
//	else
//		ft_putstr(s);
}

void	ft_int_flag(va_list ap, s_data *data, int nb)
{
	(data->preci -= ft_intcount(nb));
	(data->size -= ft_intcount(nb));
/*	if (data->preci > 0 && !data->flag_0)
		(nb > 0 ? data->size -= data->preci : (data->size -= ++data->preci));
	else
		data->preci = 0;
//	printf("preci==%d\tsize==%d\tnb==%d\n", data->preci, data->size, ft_intcount(nb));
*/	while (!data->flag_m && data->size-- > 0)
		write(1, " ", 1);
/*	if (nb < 0 && !ft_compar("xX", data->c))
	{
		write(1, "-", 1);
		nb *= -1;
	}*/
	ft_compar("id", data->c) && nb < 0 && write(1, "-", 1) && (nb *= -1);
	while (data->preci-- > 0)
		write(1, "0", 1);
	if (data->flag_m)
	{	//--------->necessite putnbr for xX, c, id (&p, u)
		if (ft_compar_data(data, "xX", data->c))
			ft_putnbr_hexa(nb, data->c);
		else
			ft_putnbr(nb);
		while (data->size-- > 0)
			write(1, " ", 1);
	}
	else if (ft_compar_data(data, "xX", data->c))
			ft_putnbr_hexa(nb, data->c);
	else
		ft_putnbr(nb);
}

void	ft_unsigned_flag(va_list ap, s_data *data, int nb)
{
	(data->preci -= ft_intcount(nb));
	(data->size -= ft_intcount(nb));
	if (data->preci > 0 && !data->flag_0)
		data->size -= data->preci;
	else
		data->preci = 0;
	while (!data->flag_m && data->size-- > 0)
		write(1, " ", 1);
	while (data->preci-- > 0)
		write(1, "0", 1);
	if (data->flag_m)
	{
			ft_putnbr(nb);
		while (data->size-- > 0)
			write(1, " ", 1);
	}
	else
		ft_putnbr(nb);
}

void	unsigned_bloc(va_list ap, s_data *data, char *fmt)
{
	unsigned int nb;
	int nb_size;

	nb = va_arg(ap, unsigned int);
	if ((nb_size = ft_intcount(nb) < data->size) && data->c == 'u')
		ft_unsigned_flag(ap, data, nb);
	else if (data->c == 'u')
	{
		ft_putnbr(nb);
//	printf("nb==%u\n", nb);
	}
}

void	num_bloc(va_list ap, s_data *data, char *fmt)
{
	int	nb;
	int nb_size;
	int	i;

	i = 0;
	nb = va_arg(ap, int);
	if ((ft_intcount(nb) < data->size) || ft_intcount(nb) < data->preci)
		ft_int_flag(ap, data, nb);
	else if (ft_compar_data(data, "xX", data->c))
		ft_putnbr_hexa(nb, data->c);
	else
		ft_putnbr(nb);
//	printf("\ns==%s\tc==%c\n", data->s, data->c); 
}

char	*ft_gest_flag(va_list ap, s_data *data, char *fmt)
{
	int nb;
	int i;

	i = 0;
	while (!ft_compar("cspdiuxXoytrewqafghjklmnbvxz%", fmt[i]) && fmt[i])
	{
//		printf("size==%s\n", &fmt[i]);
		if (fmt[i] == '*')
			data->size = va_arg(ap, int) && (i += 2);
		else if (fmt[i] == '0')
			data->flag_0 = 1;
		/*else */if (ft_isdigit(fmt[i]))
		{
			data->size = ft_atoi(&fmt[i]);
			while (ft_isdigit(fmt[i]))
				i++;
		}
		else if (fmt[i] == '.')
		{
			if (fmt[++i] == '*')
				data->preci = va_arg(ap, int) && i++;
			data->flag_p = 1;
			ft_isdigit(fmt[i]) && (data->preci = ft_atoi(&fmt[i]));
			while (ft_isdigit(fmt[i]))
				i++;
		}
		else if (fmt[i++] == '-')
			data->flag_m = 1;
		if (data->flag_m || data->flag_0 || data->flag_p)
			data->flag = 1;
	}
//	printf("f-==%d\n", data->flag_m);
	return (fmt + i);
}

char	*ft_preci(va_list ap, s_data *data, char *fmt)
{
	char *res;
	int i;

	i = 0;
	!ft_compar("cspdiuxX", fmt[i]) && (fmt = ft_gest_flag(ap, data, fmt));

	data->c = fmt[i];
	if (ft_compar("cdixX", fmt[i]))
		num_bloc(ap, data, &fmt[i]);
	if (fmt[i] == 's')
		str_bloc(ap, data, &fmt[i]);
	if (ft_compar("up", fmt[i]))
		unsigned_bloc(ap, data, &fmt[i]);
	return (fmt + i);
}

int ft_printf(char *fmt, ...)
{
	va_list ap;
//	va_list ap2;

	va_start(ap, fmt);
//	va_copy(ap2, ap);

	s_data data;

	while (*fmt)
	{
		if (*fmt == '%')
			fmt = ft_preci(ap, init_struct(&data), ++fmt);
		else
			write(1, fmt, 1);
		fmt++;
	}	
	va_end(ap);
	return (1);
}

int main()
{
//	unsigned int i = -2172645;
	unsigned int i = -147483690;
//	ft_printf("%*s\tgglg%10i\n", 15, "12345", 15);
//	printf("%*s\tgglg%10i\n", 15, "12345", 15);
	ft_printf("[MINE]|%-2c| |%.10s|  gggg   %.3x\n", 'a', "01234567890123456789", -42);
	printf("[TRUE]|%-2c| |%.30s|  gggg   %.3x\n", 'a', "01234567890123456789", -42);
	ft_printf("[MINE]|%.2s| |%2s| |%10.2s| |%.10s|\n", "012345", "012345", "012345", "012345");
	printf("[TRUE]|%.2s| |%2s| |%10.2s| |%.10s|\n", "012345", "012345", "012345", "012345");
//	printf("[True]|%14.12i| %10s  gggg   %.3x\n", i, "01234567890123456789", -42);
//	printf("[True]|%012.10i|", i);
//	printf("[True]%-10d\n", i);
//	printf("%*d, %3s\n",10, i, "fghjk");
	return (0);
}

