/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:04:57 by iaduquen          #+#    #+#             */
/*   Updated: 2020/03/02 19:13:44 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./includes/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_struct
{
	int		flag;
	int		flag_m;
	int		flag_p;
	int		flag_0;
	int		size;
	int		preci;
	char	c;
}				t_data;

t_data			*init_struct(t_data *data);
int				ft_num_bloc(va_list ap, t_data *data, char *fmt);
void			ft_pprint(long unsigned int nb, char c);
int				ft_int_flag(va_list ap, t_data *data, long long nb);
int				str_bloc(va_list ap, t_data *data, char *fmt);
int				null_str(va_list ap, t_data *data);
char			*ft_utoa(long long unsigned n);
int				len_digit(long long unsigned n);
int				ft_p(va_list ap, t_data *data);
int				ft_unsigned_bloc(va_list ap, t_data *data);
int				ft_printf(char *fmt, ...);
int				ft_pourcent(va_list ap, t_data *data);
int				null_nb(int size);
void			ft_putdbstr(char *s1, char *s2);
int				ft_null_p(t_data *data);

int				ft_putnbr_hex(unsigned int n, char c);
int				ft_count(long long n, char c);
char			*ft_rev_str(char *str);
int				ft_verif(char c);
int				ft_matoi(char **s);
void			ft_uputnbr(long long n);

#endif
