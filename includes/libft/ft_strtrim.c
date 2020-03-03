/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:12:14 by iaduquen          #+#    #+#             */
/*   Updated: 2020/02/28 20:01:23 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	int		length;
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	length = 0;
	while (s1[i] && ft_compar((char*)set, s1[j]))
		i++;
	while (s1[j] && ft_compar((char*)set, s1[j]))
		j--;
	if (j - i >= 0)
		length = (j - i) + 1;
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (i <= j)
		str[k++] = s1[i++];
	str[k] = 0;
	return (str);
}
