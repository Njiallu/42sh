/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_move_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchraib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:10:40 by brchraib          #+#    #+#             */
/*   Updated: 2018/12/18 17:10:41 by brchraib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int	is_boucle_h_e_pu_pd(t_data *data, char *buf)
{
	if ((buf[0] == 27 && buf[1] == 91 && buf[2] == 72 && buf[3] == 0) ||
			(buf[0] == 1 && buf[1] == 0))
		boucle_home(data);
	else if ((buf[0] == 27 && buf[1] == 91 && buf[2] == 70 && buf[3] == 0) ||
			(buf[0] == 5 && buf[1] == 0))
		boucle_end(data);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 53
		&& buf[3] == 126 && buf[4] == 0)
		real_page_up(data);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 54
		&& buf[3] == 126 && buf[4] == 0)
		real_page_down(data);
	else
		return (0);
	return (1);
}
