/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeleal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:29:36 by jeleal            #+#    #+#             */
/*   Updated: 2019/01/25 10:10:52 by jeleal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*res;

	res = (char*)mallocp(size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
		res[i++] = '\0';
	return (res);
}
