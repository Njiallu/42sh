/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:44:50 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:44:53 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	move_left_simple(t_data *data)
{
	exec_tcap("le");
	data->index--;
}

void	move_right_simple(t_data *data)
{
	exec_tcap("nd");
	data->index++;
}

void	move_r2l(t_data *data)
{
	exec_tcap("do");
	exec_tcap("cr");
	data->index++;
}

void	move_l2r(t_data *data)
{
	int	i;

	exec_tcap("up");
	exec_tcap("cr");
	i = 0;
	while (i < data->win_x)
	{
		exec_tcap("nd");
		i++;
	}
	data->index--;
}
