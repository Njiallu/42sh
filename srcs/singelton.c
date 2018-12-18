/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singelton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:58:28 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:58:30 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

t_termios	*singleton_termios(t_termios *termios, int i)
{
	static t_termios *singleton = NULL;

	if (i)
		singleton = termios;
	return (singleton);
}

t_data		*singleton_data(t_data *termios, int i)
{
	static t_data *singleton = NULL;

	if (i)
		singleton = termios;
	return (singleton);
}
