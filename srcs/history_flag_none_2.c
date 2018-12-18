/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_flag_none_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:06:09 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:41:00 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void			print_line_info(t_history *list, int i, int flg, t_cmd *cmd)
{
	putnbr_builtin(cmd, i, 1);
	if (flg == 1)
	{
		putchar_builtin(cmd, ' ', 1);
		if (list->time > 0)
			putnbr_builtin(cmd, list->time, 1);
		else
			putstr_builtin(cmd, "[NO TIMESTAMP]", 1);
	}
	putchar_builtin(cmd, ' ', 1);
	putstr_builtin(cmd, list->line, 1);
	putchar_builtin(cmd, '\n', 1);
}
