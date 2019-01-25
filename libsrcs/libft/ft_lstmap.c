/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeleal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:24:48 by jeleal            #+#    #+#             */
/*   Updated: 2019/01/25 10:10:00 by jeleal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *ret;

	newlist = f(lst);
	ret = newlist;
	while (lst->next != NULL)
	{
		lst = lst->next;
		newlist->next = f(lst);
		newlist = newlist->next;
	}
	newlist = f(lst);
	newlist->next = NULL;
	return (ret);
}
