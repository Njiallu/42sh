/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigwinch_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:58:09 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:58:12 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	petit_rectangle(t_data *data)
{
	int len_prompt_cmd;
	int rectangle;

	if ((len_prompt_cmd = (data->len_prompt + (int)ft_strlen(data->cmd))) >=
		(rectangle = (data->win_x * data->win_y)))
	{
		data->index_min_win = (int)ft_strlen(data->cmd);
		rectangle = rectangle - (data->win_x - (len_prompt_cmd % data->win_x));
		while (rectangle > 0)
		{
			data->index_min_win--;
			rectangle--;
		}
		if (data->index_min_win > data->index)
			data->index = data->index_min_win;
	}
	else
		data->index_min_win = -1;
}
