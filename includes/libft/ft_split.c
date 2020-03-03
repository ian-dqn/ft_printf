/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:07:43 by iaduquen          #+#    #+#             */
/*   Updated: 2019/12/16 17:58:35 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free(char *str, size_t count)
{
	while (--count)
		if (str[count])
			free(&str[count]);
	if (str)
		free(str);
	return (NULL);
}

static int		ft_count(char const *s, char c)
{
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		count++;
	}
	return (count);
}

static char		*ft_words(char const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			if (!(str[i++] = ft_words(&s[j], c)))
				return (ft_free(*str, i));
			while (s[j] && s[j] != c)
				j++;
		}
	}
	str[i] = NULL;
	return (str);
}
