/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:52:20 by iaduquen          #+#    #+#             */
/*   Updated: 2020/03/02 15:52:38 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putnbr_hexa(long long n, char *base)
{
	char	*base;
	int		len;

	len = ft_strlen(base);
	if (n >= len)
	{
		ft_putnbr_hexa((n / len), base);
		ft_putnbr_hexa((n % len), base);
	}
	else
		write(1, &base[n], 1);
	return (1);
}
