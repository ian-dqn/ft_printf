/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 00:20:24 by iaduquen          #+#    #+#             */
/*   Updated: 2019/11/29 19:38:56 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list		*newlst;

	if (!(newlst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	newlst->content = content;
	newlst->next = NULL;
	return (newlst);
}
