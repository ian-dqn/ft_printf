/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:32:38 by iaduquen          #+#    #+#             */
/*   Updated: 2020/02/10 15:29:41 by iaduquen         ###   ########.fr       */
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

void	null_str(va_list ap, s_data *data)
{
	(data->preci < 6 && data->preci > -1 ? data->size -= data->preci : (data->size -= 6));
	while (!data->flag_m && data->size-- > 0)
		write (1, " ", 1);
	if (data->preci < 6 && data->preci > -1)
		write(1, "(null)", data->preci);
	else
		write(1, "(null)", 6);
	while (data->size-- > 0)
		write (1, " ", 1);
	return ;

}

void	str_bloc(va_list ap, s_data *data, char *fmt)
{
	char	*s;
	int		i;
	int		len;
	int		data_size;

	s = va_arg(ap, char *);
	if (!s)
	{
		null_str(ap, data);
		return ;
	}
	len = ft_strlen(s);
	data->preci > -1 && data->preci < len && (len = data->preci);
	while (!data->flag_m && data->size-- > len)
		(data->flag_0 ? write(1, "0", 1) : write(1, " ", 1));
	write(1, s, len);
	while (data->size-- > len)
		write(1, " ", 1);
}

void	ft_char_flag(va_list ap, s_data *data)
{
	char c;

	c = va_arg(ap, int);
	while (!data->flag_m && --data->size > 0)
		write(1, " ", 1);
	if (data->flag_m)
	{
		write(1, &c, 1);
		while (--data->size > 0)
			write(1, " ", 1);
	}
	else
		write(1, &c, 1);
}

void	ft_int_flag(va_list ap, s_data *data, int nb)
{
	//	printf("1.size==%d, preci==%d\n", data->size, data->preci);
	(data->preci -= ft_intcount(nb));
	(data->size -= ft_intcount(nb));
	(data->preci > 0 ? data->size -= data->preci : 0);
	//	printf("size==%d, preci==%d, int_size==%d\n", data->size, data->preci, ft_intcount(nb));
	(nb < 0 ? data->size-- : 0);
	if (data->flag_0 && !data->flag_p)
	{
		ft_compar("id", data->c) && nb < 0 && write(1, "-", 1) && (nb *= -1);
		while (!data->flag_m && data->size-- > 0)
			write(1, "0", 1);
	}
	while (!data->flag_m && /*!data->flag_0 &&*/ data->size-- > 0)
		write(1, " ", 1);
	ft_compar("id", data->c) && nb < 0 && write(1, "-", 1) && (nb *= -1);
	while (data->preci-- > 0 || (data->flag_0 && !data->flag_m && data->size-- > 0))
		write(1, "0", 1);
	if (data->flag_m)
	{
		if (ft_compar_data(data, "xX", data->c))
			ft_putnbr_hexa(nb, data->c);
		else
			ft_putnbr(nb);
		while (data->size-- > 0)
			(data->flag_0 ? write(1, "0", 1) : write(1, " ", 1));
	}
	else if (ft_compar_data(data, "xX", data->c))
		ft_putnbr_hexa(nb, data->c);
	else
		ft_putnbr(nb);
}

void	ft_unsigned_flag(va_list ap, s_data *data, int nb)
{
	int len;

	data->c == 'p' ? (len = 11) : (len = ft_intcount(nb));
	(data->preci -= len);
	(data->size -= len);
	(data->preci > 0 ? data->size -= data->preci : 0);
	//	printf("|size==%d, preci==%d, int_size==%d\n|", data->size, data->preci, len);
	if (data->flag_0 && !data->flag_p)
		while (!data->flag_m && data->size-- > 0)
			write(1, "0", 1);
	while (!data->flag_m && data->size-- > 0)
		write(1, " ", 1);
	while (data->preci-- > 0 || (data->flag_0 && !data->flag_m && data->size-- > 0))
		write(1, "0", 1);
	if (data->flag_m)
	{
		ft_putnbr(nb);
		while (data->size-- > 0)
			(data->flag_0 ? write(1, "0", 1) : write(1, " ", 1));
	}
	else
		ft_putnbr(nb);

}

void	unsigned_bloc(va_list ap, s_data *data, char *fmt)
{
	unsigned int nb;
	int nb_size;

	nb = va_arg(ap, unsigned int);
	/*	if (data->c == 'p')
		nb *= 0x100;
*/	
	if (nb == 0 && data->preci == 0)
		while(data->size-- > 0)
			write (1, " ", 1);
//	(data->c == 'p' ? (nb_size = ft_intcount(nb) + 4) : (nb_size = ft_intcount(nb)));
	else if ((nb_size = ft_intcount(nb) < data->size || nb_size < data->preci))
		ft_unsigned_flag(ap, data, nb);
/*	else
	{
		data->c == 'p' ? ft_putnbr_hexa(nb, 'p') : ft_putnbr(nb);
//	printf("nb==%u\n", nb);
	}*/
}

void	num_bloc(va_list ap, s_data *data, char *fmt)
{
	int	nb;
	int nb_size;
	int	i;

	i = 0;
	nb = va_arg(ap, int);
	if (nb == 0 && data->preci == 0)
		while(data->size-- > 0)
			write (1, " ", 1);
	else if ((ft_intcount(nb) < data->size) || ft_intcount(nb) < data->preci)
		ft_int_flag(ap, data, nb);
	else if (ft_compar_data(data, "xX", data->c))
		ft_putnbr_hexa(nb, data->c);
	else
		ft_putnbr(nb);
//	printf("\ns==%s\tc==%c\n", data->s, data->c); 
}

char	*ft_gest_flag(va_list ap, s_data *data, char *fmt)
{
	int	nb;
	int	i;

	i = 0;
	while (!ft_compar("cspdiuxX%", fmt[i]) && fmt[i])
	{
//		printf("size==%s\n", &fmt[i]);
		if (fmt[i] == '*')
			data->size = va_arg(ap, int) && (i += 2);
		else if (fmt[i] == '0')
		{
			data->flag_0 = 1;
			i++;
		}
		if (ft_isdigit(fmt[i]))
		{
			//!data->flag_0 ? (data->size = ft_atoi(&fmt[i])) : (data->preci = ft_atoi(&fmt[i]));
			data->size = ft_atoi(&fmt[i]);
			while (ft_isdigit(fmt[i]))
				i++;
		}
		else if (fmt[i] == '.')
		{
			data->preci = 0;
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
	if (fmt[i] == 'c')
		ft_char_flag(ap, data);
	if (ft_compar("dixX", fmt[i]))
		num_bloc(ap, data, &fmt[i]);
	if (fmt[i] == 's')
	{
//	printf("preci==%d\tsize==%d\tc==%c\n", data->preci, data->size,  data->c);
		str_bloc(ap, data, &fmt[i]);
	}
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
/*
int main()
{
//	unsigned int i = -2172645;
	unsigned int i = 147483690;
	char *s = "";
	char a = 'a';
//	ft_printf("%*s\tgglg%10i\n", 15, "12345", 15);
//	printf("%*s\tgglg%10i\n", 15, "12345", 15);
//	ft_printf("[MINE]|%-2c| |%-12.10s|  gggg   %.3x\n", 'a', "01234567890123456789", -42);
//	printf("[TRUE]|%-2c| |%-12.10s|  gggg   %.3x\n", 'a', "01234567890123456789", -42);
//	ft_printf("[MINE]|%.2s| |%2s| |%10.2s| |%.10s|\n", "012345", "012345", "012345", "012345");
//	printf("[TRUE]|%.2c| |%2c| |%10.2c| |%.10c|\n", a, a, a, a);
//	ft_printf("[MINE]|%.2c| |%2c| |%10.2c| |%.10c|\n", a, a, a, a);
//	ft_printf("[MINE]|%2s|\n", "012345");
//	printf("[TRUE]|%10.8s| |%2s| |%10.2s| |%.10s|\n", "012345", "012345", "012345", "012345");
//	printf("[True]|%14.12i| %10s  gggg   %.3x\n", i, "01234567890123456789", -42);
	printf("[TRUE]|%12s|\n", NULL);
	ft_printf("[MINE]|%5.9s|\n", NULL);
//	ft_printf("[MINE]|%7u|\n", 33);
//	ft_printf("[MINE]|%12p|,|%5u|\n", s, i);
//	ft_printf("[MINE]|%.2c|,|%4.2c|\n", 'a', 'b');
//	printf("%*d, %3s\n",10, i, "fghjk");
//	ft_printf("%s", "");
	return (0);
}
*/
