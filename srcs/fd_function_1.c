/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_function_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:19:54 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:19:55 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void		close_fd(t_fd *fd)
{
	while (fd)
	{
		if (fd->fd > 2)
			close(fd->fd);
		fd = fd->next;
	}
}

void		close_fd_cmd(t_cmd *cmd)
{
	while (cmd)
	{
		close_fd(cmd->fd_in);
		close_fd(cmd->fd_out);
		close_fd(cmd->fd_err);
		cmd = cmd->next;
	}
}

t_fd		*create_fd(int fd, int fd_pointe)
{
	t_fd	*elem;

	elem = (t_fd*)mallocp(sizeof(t_fd));
	elem->next = NULL;
	elem->fd = fd;
	elem->fd_pointe = fd_pointe;
	return (elem);
}

t_fd		*add_fd_elem(t_fd *list, t_fd *elem)
{
	t_fd *tmp;

	tmp = list;
	if (list == NULL)
		return (elem);
	while (list->next != NULL)
		list = list->next;
	list->next = elem;
	if (list->fd < 0)
	{
		free(list);
		return (elem);
	}
	return (tmp);
}

t_fd		*copy_fd(t_fd *list)
{
	t_fd *copy;

	copy = NULL;
	while (list)
	{
		copy = add_fd_elem(copy, create_fd(dup(list->fd), list->fd_pointe));
		list = list->next;
	}
	return (copy);
}
