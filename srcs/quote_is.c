/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:56:34 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:56:37 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			is_quote(char car)
{
	if (car == '\'' || car == '"' || car == '`' || car == '(' || car == ')'
			|| car == '[' || car == ']' || car == '{' || car == '}')
		return (1);
	return (0);
}

int			is_quote_open(char car)
{
	if (car == '\'' || car == '"' || car == '`' || car == '('
			|| car == '[' || car == '{')
		return (1);
	return (0);
}

int			is_quote_close(char car, char open)
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
	return (0);
}
