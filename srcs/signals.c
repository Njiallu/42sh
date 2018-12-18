/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:57:56 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:57:59 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	signal_end_prog(int sig)
{
	t_data *data;

	invert_term();
	free(singleton_termios(NULL, 0));
	data = singleton_data(NULL, 0);
	history_exit(data);
	delete_list(data->env);
	delete_heredocs(data);
	delete_list_history(data->history);
	delete_list_var(data->var);
	delete_list_auto(data->list_auto);
	delete_data(data);
	exit(sig);
}

void	signal_handler(void)
{
	int	i;

	i = 1;
	while (i < 28)
	{
		if (i != SIGSTOP && i != SIGTTOU && i != SIGTSTP && i != SIGTTIN
			&& i != SIGWINCH && i != SIGINT && i != SIGURG
			&& i != SIGIO && i != SIGCHLD && i != SIGCONT)
			signal(i, signal_end_prog);
		if (i == SIGCONT || i == SIGTSTP)
			signal(i, SIG_IGN);
		i++;
	}
}
