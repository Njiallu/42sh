/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_advanced_tilde.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:55:37 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:55:40 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			is_tilde_and_replace(t_data *data, char **str, size_t *index)
{
	char	*home;
	char	*tmp;

	if (((*str)[*index] == '~' && !is_escaped_char(*str, *index) &&
		(ft_isspace2((*str)[*index]) || (*str)[*index + 1] == '/'
		|| (*str)[*index + 1] == '\0')))
	{
		home = find_var_env(data, "HOME", data->env);
		if (home)
		{
			(*str)[*index] = '\0';
			tmp = ft_strjoinaf1(ft_strjoin(*str, home), *str + *index + 1);
			free(*str);
			*str = tmp;
			(*index) += ft_strlen(home);
		}
		free(home);
	}
	return (1);
}
