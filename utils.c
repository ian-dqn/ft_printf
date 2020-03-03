/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:42:55 by iaduquen          #+#    #+#             */
/*   Updated: 2020/03/02 15:28:03 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_verif(char c)
{
	if (ft_compar("cspdiuxX%*-.", c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

int		len_digit(long long unsigned nb)
{
	int	l;

	l = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		l++;
	}
	if (l > 8)
		l = 8;
	return (l);
}

char	*ft_utoa(long long unsigned n)
{
	char					*str;
	long long unsigned		nb;
	int						i;
	char					*tab;

	tab = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	i = len_digit(n) + 1;
	if (!(str = (char*)malloc(sizeof(char) * (i + 3))))
		return (NULL);
	i = 0;
	while (nb > 0)
	{
		str[i] = tab[nb % 16];
		nb = nb / 16;
		i++;
	}
	str[i] = 0;
	str = ft_rev_str(str);
	return (str);
}

void	ft_putdbstr(char *s1, char *s2)
{
	write(1, s1, ft_strlen(s1));
	write(1, s2, ft_strlen(s2));
}

t_data	*init_struct(t_data *data)
{
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data->flag = 0;
	data->flag_0 = 0;
	data->flag_m = 0;
	data->flag_p = 0;
	data->preci = -1;
	data->size = 0;
	return (data);
}
