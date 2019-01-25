/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeleal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:40:40 by jeleal            #+#    #+#             */
/*   Updated: 2019/01/25 10:07:54 by jeleal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char *cur;

	if (n != 0)
	{
		cur = (unsigned char*)s;
		while (n--)
		{
			*cur = 0;
			if (n)
				cur++;
		}
	}
}
