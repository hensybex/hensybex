/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:53:41 by medesmon          #+#    #+#             */
/*   Updated: 2019/01/20 19:37:00 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*lst2;

	if (!f || !lst)
		return (NULL);
	if (!(lst2 = f(lst)))
		return (NULL);
	newlst = lst2;
	while (lst->next)
	{
		lst = lst->next;
		if (!(lst2->next = f(lst)))
		{
			while (newlst)
			{
				lst2 = newlst->next;
				free(newlst);
				newlst = lst2;
			}
			return (NULL);
		}
		lst2 = lst2->next;
	}
	return (newlst);
}
