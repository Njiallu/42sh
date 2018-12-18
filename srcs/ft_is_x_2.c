/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_x_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:20:40 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:20:41 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int		is_builtin(char *cmd)
{
	if (cmd[0] == 'e')
	{
		if (ft_strequ(cmd, "exit") || ft_strequ(cmd, "env") ||
			ft_strequ(cmd, "echo") || ft_strequ(cmd, "export"))
			return (1);
		else
			return (0);
	}
	else if (ft_strequ(cmd, "cd") || ft_strequ(cmd, "setenv")
		|| ft_strequ(cmd, "unsetenv") || ft_strequ(cmd, "source")
		|| ft_strequ(cmd, "history") || ft_strequ(cmd, "setvar")
		|| ft_strequ(cmd, "unset"))
		return (1);
	else
		return (0);
}

int		is_key(t_data *data)
{
	if (ft_strequ(data->cmd, data->key_here))
		return (1);
	return (0);
}
