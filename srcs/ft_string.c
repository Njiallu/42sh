/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:20:47 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:20:48 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

char	*insert_char(char *str, int index, char c)
{
	char *ret;

	ret = (char*)mallocp(sizeof(char) * (ft_strlen(str) + 2));
	ft_strncpy(ret, str, index);
	ret[index] = c;
	ft_strcpy(ret + index + 1, str + index);
	free(str);
	return (ret);
}

char	*delete_char(char *str, int index)
{
	char *ret;

	ret = (char*)mallocp(sizeof(char) * ft_strlen(str));
	ft_strncpy(ret, str, index - 1);
	ft_strcpy(ret + index - 1, str + index);
	free(str);
	return (ret);
}
