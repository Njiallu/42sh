/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeleal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:35:25 by jeleal            #+#    #+#             */
/*   Updated: 2019/01/25 10:10:48 by jeleal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	n--;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && i < n &&
			(unsigned char)s1[i] != '\0' && (unsigned char)s2[i] != '\0')
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
