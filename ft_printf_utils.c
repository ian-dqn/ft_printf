/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 08:36:03 by iaduquen          #+#    #+#             */
/*   Updated: 2020/01/10 16:19:06 by iaduquen         ###   ########.fr       */
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
	data->preci = 0;
	data->c = 'i';
	data->s = ft_strdup("");
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

char			*ft_itoa(int n)
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

void	ft_putnbr_hexa(int n, char c)
{
	char *base;
	unsigned int nb;
	int len;

	if (!(base = (char *)malloc (17)))
		return ;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	nb = n;
	len = ft_strlen(base);
	if (nb >= len)
	{
		ft_putnbr_hexa((nb / len), c);
		ft_putnbr_hexa((nb % len), c);
	}
	else
		write(1, &base[nb], 1);
}

void	ft_putnbr(long n)
{
//	printf("nb == %ld", n);
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



char	*ft_itoa_hexa(s_data *data, int n, int nb_size)
{
	char			*base;
	char			*s;
	int				i;
	int				j;
	unsigned int	nb;

	if (!(base = (char *)malloc(17)) || !(s = (char *)malloc(sizeof(char) * (16 + 1))))
		return (NULL);
	nb = n;
	i = 1;
	j = 0;
	if (data->c == 'x')
		base = "0123456789abcdef";
	if (data->c == 'X')
		base = "0123456789ABCDEF";
	while (nb > 0)
	{
		while (n > 16)
		{
			n %= 16;
			i++;
		}
		s[j++] = base[nb % (i - 1)];
		nb = nb / (16 * (i - 1));
	}
	return (s);
}
