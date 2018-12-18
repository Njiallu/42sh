/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:27:25 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:27:26 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

t_history		*create_history_elem(char *content)
{
	struct timeval	tv;
	t_history		*elem;

	elem = (t_history*)mallocp(sizeof(t_history));
	elem->line = ft_strdup(content);
	gettimeofday(&tv, NULL);
	elem->time = (int)tv.tv_sec;
	elem->get_from_file = 0;
	elem->next = NULL;
	elem->prec = NULL;
	return (elem);
}

t_history		*add_history_elem(t_history *list, t_history *elem)
{
	if (list == NULL)
		return (elem);
	if (ft_strequ(elem->line, list->line))
	{
		free(elem->line);
		free(elem);
		return (list);
	}
	list->next = elem;
	elem->prec = list;
	return (elem);
}
