/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeleal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:41:00 by jeleal            #+#    #+#             */
/*   Updated: 2019/01/25 10:10:10 by jeleal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int						i;
	unsigned const char		*ch1;
	unsigned const char		*ch2;

	ch1 = (unsigned char *)s1;
	ch2 = (unsigned char *)s2;
	i = 0;
	while (i < (int)n)
	{
		if (ch1[i] == ch2[i])
			i++;
		else
			return ((unsigned char)ch1[i] - (unsigned char)ch2[i]);
	}
	return (0);
}
