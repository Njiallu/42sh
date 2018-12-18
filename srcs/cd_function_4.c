/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_function_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:12:59 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:13:01 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static char		**defrag(char **s, size_t len)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strcmp("..", s[i]) == 0 && i > 0)
		{
			ft_strdel(&s[i - 1]);
			ft_str2defrag(s, len);
			ft_strdel(&s[i - 1]);
			ft_str2defrag(s, len);
			i = 0;
		}
		else if (ft_strcmp(".", s[i]) == 0)
		{
			free(s[i]);
			s[i] = NULL;
			ft_str2defrag(s, len);
			i = 0;
		}
		else
			i++;
	}
	return (s);
}

char			*troncate_dots(char *path)
{
	char	**s;
	char	*str;

	if (path[0] == '/')
	{
		s = ft_lz_strsplit(&path[1], '/');
	}
	else
	{
		s = ft_lz_strsplit(&path[0], '/');
	}
	s = defrag(s, ft_str2len(s));
	str = join_slash(s);
	ft_strdel(&path);
	return (str);
}

int				operate_legal_opts(char **str, t_cmd *cmd, t_data *data)
{
	size_t	i;
	int		o;

	i = 1;
	o = 0;
	while (str[i])
	{
		if (str[i][0] == '-' && !is_minus(str[i]))
		{
			if ((is_physical(str[i]) || is_logical(str[i])) && o == 0)
				o++;
			else if (o && (is_physical(str[i]) || is_logical(str[i])))
				return (0);
			else
			{
				display_cd_invalid_option(str[i], cmd, data);
				return (-1);
			}
		}
		else
			return (1);
		i++;
	}
	return (1);
}
