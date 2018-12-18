/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:16:39 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:16:40 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	delete_list_env(t_env *list)
{
	t_env *tmp;

	while (list)
	{
		tmp = list->next;
		free(list->name);
		free(list->arg);
		free(list);
		list = tmp;
	}
}

void	delete_list_var(t_var *list)
{
	t_var *tmp;

	while (list)
	{
		tmp = list->next;
		free(list->name);
		free(list->arg);
		free(list);
		list = tmp;
	}
}

void	delete_list_env_and_var(t_data *data)
{
	delete_list_env(data->env);
	delete_list_var(data->var);
}

void	reinit_list_auto(t_data *data)
{
	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
}
