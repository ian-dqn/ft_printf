/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:36:48 by iaduquen          #+#    #+#             */
/*   Updated: 2019/12/10 16:54:29 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst || !del || !f)
		return (NULL);
	while (lst)
	{
		if (!(new_lst = (t_list *)malloc(sizeof(t_list))))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_lst = f(lst->content);
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (new_lst);
}
