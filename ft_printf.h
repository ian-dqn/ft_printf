/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 08:35:54 by iaduquen          #+#    #+#             */
/*   Updated: 2020/01/25 20:09:26 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
/*if '.', flag == 1;
**if '-', flag == 2;
**if '0', flag == 3;
*/



typedef struct printf_struct
{
	va_list ap;
	int flag;
	int	flag_m;
	int	flag_p;
	int	flag_0;
	int size;
	int	preci;
	char	c;
	char	*s;
}	s_data;

s_data	*init_struct(s_data *data);
char *ft_strmccpy(s_data *data, char c, int len);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ft_isdigit(char c);
int		ft_compar(char *set, char c);
int		ft_compar_data(s_data *data, char *set, char c);
int		ft_intcount(int n);
void	ft_putnbr(long n);
void	ft_putnbr_hexa(int n, char c);
int 	ft_atoi(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_itoa_hexa(s_data *data, int n, int nb_size);

#endif
