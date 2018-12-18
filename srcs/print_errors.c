/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:56:20 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:56:23 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	print_cmd_not_found(char *scmd)
{
	ft_putstr_fd("42sh: command not found: ", 2);
	ft_putstr_fd(scmd, 2);
	ft_putchar_fd('\n', 2);
}

int		print_pipe_error(void)
{
	ft_putstr_fd("42sh: parse error near '|' or '&'\n", 2);
	return (1);
}
