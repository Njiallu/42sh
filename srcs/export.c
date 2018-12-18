/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:19:38 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:19:41 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			ft_export(char **scmd, t_env **env, t_cmd *cmd)
{
	char *arg;

	if (!scmd[1])
	{
		print_env(*env, cmd);
		return (0);
	}
	if (scmd[2])
		arg = ft_strdup(scmd[2]);
	else
		arg = ft_strdup("");
	if (isset_arg(*env, scmd[1]))
		change_arg(*env, scmd[1], arg);
	else
		*env = add_elem_end(*env, scmd[1], arg);
	free(arg);
	return (0);
}
