/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_str_with_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeleal <jeleal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:14:31 by jeleal            #+#    #+#             */
/*   Updated: 2019/01/25 10:07:47 by jeleal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_alloc_str_with_char(int c)
{
	char	*ret;

	ret = (char*)mallocp(2 * sizeof(char));
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}
