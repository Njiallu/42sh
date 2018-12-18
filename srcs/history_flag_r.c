/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_flag_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:41:35 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:41:38 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int		history_flag_r(t_data *data, char *scmd, t_cmd *cmd)
{
	char		*path;
	char		*line;

	if (get_history_path_anrw(data, &path, scmd) == 1)
		return (1);
	data->history_fd = open(path, O_RDONLY);
	free(path);
	if (data->history_fd == -1)
		return (1);
	line = NULL;
	while (get_next_line(data->history_fd, &line) == 1)
	{
		get_history_command_part(line);
		data->history = add_history_elem(data->history,
				create_history_elem(line + get_history_command_part(line)));
		data->history->time = ft_atoi(line);
		free(line);
	}
	if (close(data->history_fd) == -1)
	{
		putstr_builtin(cmd, "42sh: history: Failed \n", 2);
		putstr_builtin(cmd, "to open/close history file\n", 2);
	}
	return (0);
}
