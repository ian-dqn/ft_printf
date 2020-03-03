/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 01:06:18 by iaduquen          #+#    #+#             */
/*   Updated: 2019/11/18 14:22:00 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *tmp;

	if (lst)
	{
		tmp = lst;
		while (lst && tmp->next)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}
