/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 08:36:03 by iaduquen          #+#    #+#             */
/*   Updated: 2020/02/03 16:23:50 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while(s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	if (s1)
		len = ft_strlen(s1);
	else
		len = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

s_data	*init_struct(s_data *data)
{
	if (!(data = (s_data *)malloc(sizeof(s_data))))
		return (NULL);
//	data->ap = ap;
	data->flag = 0;
	data->flag_0 = 0;
	data->flag_m = 0;
	data->flag_p = 0;
	data->preci = -1;
	data->size = 0;
	data->c = 'i';
//	data->s = ft_strdup("");
	return (data);
}

char *ft_strmccpy(s_data *data, char c, int len)
{
	char *s;
	int i;

	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		s[i++] = c;
	free(data->s);
	return (s);
}

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

int ft_isdigit(char c)
{
	return(c >= '0' && '9' >= c ? 1 : 0);
}

int	ft_compar_data(s_data *data, char *set, char c)
{
	while (*set)
		if (c == *set++)
		{
			data->c = c;
			return (1);
		}
	return (0);
}

int	ft_compar(char *set, char c)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

int	ft_intcount(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	return (++count);
}

char			*ft_itoa(long n)
{
	char			*str;
	int				i;
	int				size;
	unsigned int	nb;

	size = ft_intcount(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (n < 0)
		nb = -n;
	else
		nb = n;
	i = size - 1;
	while (nb >= 10)
	{
		str[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	str[i] = nb % 10 + 48;
	str[size] = '\0';
	return (str);
}

int	ft_putnbr_hexa(long n, char c)
{
	char *base;
	int len;

	if (!(base = (char *)malloc (17)))
		return 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
/*	if (c == 'p')
	{
		ft_putstr("0x");
		write(1, "0x", 2);
	}
*/	len = ft_strlen(base);
	if (n >= len)
	{
		ft_putnbr_hexa((n / len), c);
		ft_putnbr_hexa((n % len), c);
	}
	else
		write(1, &base[n], 1);
	return (1);
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

int ft_atoi(char *s)
{
	int res;
	char *str;

	res = 0;
	while (*s && ft_isdigit(*s))
	{
		res = (res * 10) + (*s - 48);
		s++;
	}
	return (res);
}



int	ft_putitoa_hexa(long n, char *base)
{
	char	*s;
	int		i;
	int		j;
	long	nb_size;
	char tmp;

	nb_size = ft_intcount(n);
	if (!(s = (char *)malloc(sizeof(char) * (12 + 1))))
		return (0);
	i = 0;
	j = 0;
	while (n > 0)
	{
		s[i++] = (base[n % 16]);
		n /= 16;
	}
	(s[i++] = 'x') && (s[i++] = '0') && (s[i] = 0);
	while (--i > j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j++] = tmp;
	}
//	write(1, "0x", 2);
	ft_putstr(s);
	free(s);
	return (1);
}
