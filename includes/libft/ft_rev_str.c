/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:27:32 by iaduquen          #+#    #+#             */
/*   Updated: 2020/03/02 15:52:03 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rev_str(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = ft_strlen(str);
	j = 0;
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i > 0)
	{
		s[j++] = str[--i];
	}
	s[j] = 0;
	free(str);
	return (s);
}
