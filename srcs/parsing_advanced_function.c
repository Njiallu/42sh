/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_advanced_function.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:55:03 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:55:05 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			is_escaped_char(char *str, int index)
{
	int ret;

	ret = 0;
	index--;
	while (index >= 0 && str[index] == '\\')
	{
		ret++;
		index--;
	}
	return (ret % 2);
}

int			is_quote_true_open(char car, char *str, int prec)
{
	if (!is_escaped_char(str, prec))
	{
		if (car == '\'' || car == '"' || car == '`' || car == '('
				|| car == '[' || car == '{')
			return (1);
	}
	return (0);
}

int			is_quote_true_close(char car, char open, char *str, int prec)
{
	if (!is_escaped_char(str, prec))
	{
		if (car == '\'' && open == '\'')
			return (1);
		else if (car == '"' && open == '"')
			return (1);
		else if (car == '`' && open == '`')
			return (1);
		else if (car == '(' && open == ')')
			return (1);
		else if (car == '[' && open == ']')
			return (1);
		else if (car == '{' && open == '}')
			return (1);
	}
	return (0);
}
