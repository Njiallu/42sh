/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeleal <jeleal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:02:45 by jeleal            #+#    #+#             */
/*   Updated: 2019/01/25 10:10:22 by jeleal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	ft_putstr(char *s)
{
	int i;

	if (s == NULL)
	{
		ft_putstr("(null)");
		return ;
	}
	i = ft_strlen(s);
	write(1, s, i);
}
