/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:32:38 by iaduquen          #+#    #+#             */
/*   Updated: 2020/01/11 19:02:42 by iaduquen         ###   ########.fr       */
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
	int		len;

	len = data->size - ft_strlen(s);
	if (data->flag_0)
		while (len-- > 0)
			write(1, "0", 1);
/*	if (!data->flag)
		while (len-- > 0)
			write(1, " ", 1);*/
	if (data->flag_m)
	{
		ft_putstr(s);
		while (len-- > 0)
			write(1, " ", 1);
	}
	else
		ft_putstr(s);
}

void	ft_int_flag(va_list ap, s_data *data, int nb)
{
	int		len;

	if (data->size > data->preci)
		len = data->size - ft_intcount(nb);
	else
		len = data->preci - ft_intcount(nb);
//	printf("len==%d\tpreci==%d\tsize==%d\n", len, data->preci, data->size);
	while (len > 0)
	{
	if (data->flag_0 || (data->flag_p) /*&& data->preci < data->size)*/)
		while (len-- > 0 /*&& data->size-- > data->preci*/)
			write(1, "0", 1);
	if (data->flag_p || (len && !data->flag_m))
		while (len-- > 0 && data->size-- > data->preci)
			write(1, " ", 1);
	if (data->flag_m)
	{
		if (ft_compar_data(data, "xX", data->c))
			ft_putnbr_hexa(nb, data->c);
		else
			ft_putnbr(nb);
		while (len-- > 0)
			write(1, " ", 1);
	}
	else if (ft_compar_data(data, "xX", data->c))
			ft_putnbr_hexa(nb, data->c);
	else
		ft_putnbr(nb);
	}
}

void	ft_unsigned_flag(va_list ap, s_data *data, int nb)
{
	int len;

	len = data->size - ft_intcount(nb);
	if (data->flag_0 || data->flag_p)
		while (len-- > 0)
			write(1, "0", 1);
	if (data->flag_0)
		while (len-- > 0)
			write(1, " ", 1);
	if (data->flag_m)
	{
		ft_putnbr(nb);
		while (len-- > 0)
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
//	printf("va_arg==%d\n", nb);
//	printf("va_arg==%d\tdata==%d\n", ft_intcount(nb), data->size);
//	printf("nb_size==%d\tsize==%d\tpreci==%d\n", ft_intcount(nb), data->size, data->preci);
	if (nb < 0 && data->flag)
	{
		write(1, "-", 1);
		nb *= -1;
	}
/*	if (data->c == 'c')
		write(1, &nb, 1);*/
	if ((ft_intcount(nb) < data->size) || ft_intcount(nb) < data->preci)
		ft_int_flag(ap, data, nb);
	else if (ft_compar_data(data, "xX", data->c))
		ft_putnbr_hexa(nb, data->c);
	else
		ft_putnbr(nb);
//	printf("\ns==%s\tc==%c\n", data->s, data->c); 
}

void	str_bloc(va_list ap, s_data *data, char *fmt)
{
	char	*s;

	s = va_arg(ap, char *);
	if (ft_strlen(s) < data->size)
		ft_str_flag(ap, data, s);
	else if (data->flag_p && ft_strlen(s) > data->size)
		write(1, s, data->size);
	else
		ft_putstr(s);
}

char	*ft_gest_flag(va_list ap, s_data *data, char *fmt)
{
	int nb;
	int i;

	i = 0;
	while (!ft_compar("cspdiuxX", fmt[i]) && fmt[i] && data->flag_p != 1)
	{
//		printf("size==%s\n", &fmt[i]);
		if (fmt[i] == '*')
			fmt[i] = (nb = va_arg(ap, int));
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
			data->flag_p = 1;
			ft_isdigit(fmt[++i]) && (data->preci = ft_atoi(&fmt[i]));
			while (ft_isdigit(fmt[i]))
				i++;
		}
		else if (fmt[i++] == '-')
			data->flag_m = 1;
	}
	if (data->flag_m || data->flag_0 || data->flag_p)
		data->flag = 1;
//	printf("f-==%d\n", data->flag_m);
	return (fmt + i);
}

char	*ft_preci(va_list ap, s_data *data, char *fmt)
{
	char *res;
	int i;

	i = 0;
	//	printf("%s\n", ft_itoa_hexa(data, 42, 2));
	//	return (NULL);
	!ft_compar("cspdiuxX", fmt[i]) && (fmt = ft_gest_flag(ap, data, fmt));
	/*while (!ft_compar("cspdiuxX.", fmt[i]) && fmt[i])
	{
		switch(fmt[i])
		{
			case '.':
				data->flag_p = 1;
				break ;
			case '-':
				data->flag_m = 1;
				break ;
			case '0':
				data->flag_0 = 3;
				i++;
				break ;
			case '*' :
				data->size = va_arg(ap, int);
				break ;
		}
		if (ft_isdigit(fmt[i]))
		{
			data->size = ft_atoi(&fmt[i]);
	//		printf("preci==%i\n", data->preci);
			while(ft_isdigit(fmt[i]))
				i++;
		}
		else
			i++;*/
//		printf("fmt==%s\n", fmt);
	//	printf("data%d\n", data->size);
	data->c = fmt[i];
//		printf("c==%c\n", data->c);
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
	va_list ap2;

	va_start(ap, fmt);
	va_copy(ap2, ap);

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
	unsigned int i = 2172645;
//	ft_printf("%11d", 535);
//	unsigned int i = 2147483690;
//	ft_putnbr_base(i, "0123456789abcdef");
//	int a = 42 / 16;
//	ft_printf("%*s\ttutu%10i\n", 15, "12345", 15);
//	printf("%*s\ttutu%10i\n", 15, "12345", 15);
//	printf("%s\n", "0123456789");
	ft_printf("[Mine]%-10d %10s  gggg   %.3x\n", i, "01234567890123456789", -42);
	printf("[True]%-10d %10s  gggg   %.3x\n", i, "01234567890123456789", -42);
//	printf("[True]%-10d\n", i);
//	printf("%*d, %3s\n",10, i, "fghjk");
	return (0);
}
