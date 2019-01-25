/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeleal <jeleal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:10:19 by jeleal            #+#    #+#             */
/*   Updated: 2019/01/25 10:10:23 by jeleal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

static unsigned int	ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

static void			ft_printing(int taille, unsigned int c)
{
	while (taille >= 0)
	{
		ft_putchar((char)(c / (ft_pow(10, taille)) + (int)'0'));
		c %= ft_pow(10, taille);
		taille--;
	}
}

void				ft_putunbr(unsigned int c)
{
	int				taille;
	unsigned int	tmp;

	if (c == 0)
		ft_putchar('0');
	tmp = c;
	taille = 0;
	while (tmp != 0)
	{
		tmp /= 10;
		taille += 1;
	}
	taille--;
	ft_printing(taille, c);
}
