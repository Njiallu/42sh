/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:59:27 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 18:00:11 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	boucle_previous_word(t_data *data)
{
	int	tmp;

	tmp = data->index - 1;
	while (tmp != data->index && data->index > 0 && data->cmd[data->index - 1] \
	!= '\n' && ft_isspace2(data->cmd[data->index - 1]))
	{
		tmp = data->index;
		move_left(data);
	}
	while (tmp != data->index && data->index > 0 && data->cmd[data->index - 1] \
	!= '\n' && !(ft_isspace2(data->cmd[data->index - 1])))
	{
		tmp = data->index;
		move_left(data);
	}
}

void		previous_word(t_data *data)
{
	if (!(data->mode_copy))
		boucle_previous_word(data);
	else
		boucle_previous_word(data);
}

void		next_word(t_data *data)
{
	if (!(data->mode_copy))
	{
		while (data->cmd[data->index] && !(ft_isspace2(data->cmd[data->index])))
			move_right_without_mod(data);
		while (data->cmd[data->index] && ft_isspace2(data->cmd[data->index]))
			move_right_without_mod(data);
	}
	else
	{
		while (data->cmd[data->index] && \
		!(ft_isspace2(data->cmd[data->index])) \
		&& data->index + 1 != (int)ft_strlen(data->cmd))
		{
			move_right(data);
		}
		while (data->cmd[data->index] && \
			ft_isspace2(data->cmd[data->index]) && \
		data->index + 1 != (int)ft_strlen(data->cmd))
			move_right(data);
	}
}
