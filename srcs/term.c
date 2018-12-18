/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:58:37 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:58:40 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

t_termios	*init_term(t_data *data)
{
	t_termios	term;
	t_termios	*ret;
	char		*name_term;

	ret = (t_termios*)mallocp(sizeof(t_termios));
	tcgetattr(0, &term);
	tcgetattr(0, ret);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (isatty(0) && tcsetattr(0, TCSADRAIN, &term) == -1)
		return (NULL);
	name_term = find_arg(data->env, "TERM");
	if (ft_strequ(name_term, "") || tgetent(NULL, name_term) == ERR)
	{
		free(name_term);
		free(ret);
		return (NULL);
	}
	free(name_term);
	return (ret);
}

int			my_putchar(int c)
{
	static int	fd = 0;

	if (!fd)
		fd = open("/dev/tty", O_RDWR);
	if (!isatty(fd))
	{
		ft_putstr("/dev/tty is not a valid tty.\n");
		exit(EXIT_FAILURE);
	}
	if (c == -1)
	{
		close(fd);
		return (c);
	}
	write(fd, &c, 1);
	return (c);
}

void		exec_tcap(char *tcap)
{
	tputs(tgetstr(tcap, NULL), 1, my_putchar);
}

void		invert_term(void)
{
	t_termios	*tmp;
	t_termios	*current;

	current = (t_termios *)mallocp(sizeof(t_termios));
	if (current && (tmp = singleton_termios(NULL, 0)))
	{
		tcgetattr(0, current);
		if (isatty(0))
			tcsetattr(0, TCSADRAIN, tmp);
		free(tmp);
		singleton_termios(current, 1);
	}
}
