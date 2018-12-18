/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_flag_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:41:15 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:41:18 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			history_flag_p(char **scmd, t_cmd *cmd)
{
	int		j;

	j = 0;
	while (scmd[j] != NULL)
	{
		putstr_builtin(cmd, scmd[j], 1);
		putchar_builtin(cmd, '\n', 1);
		j++;
	}
	return (0);
}
