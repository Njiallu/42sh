/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:42:53 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:42:56 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	free_heredoc(t_data *data, t_hc *list)
{
	t_hc *tmp;

	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
	data->heredocs = NULL;
}

void	display_heredoc(t_hc *elem)
{
	int	i;

	i = 0;
	while (elem)
	{
		i++;
		elem = elem->next;
	}
}

t_hc	*create_hc_elem(char *content)
{
	t_hc	*elem;

	elem = mallocp(sizeof(t_hc));
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

t_hc	*add_hc_elem(t_hc *list, t_hc *elem)
{
	t_hc *tmp;

	tmp = list;
	if (list == NULL)
		return (elem);
	while (list->next != NULL)
		list = list->next;
	list->next = elem;
	return (tmp);
}
