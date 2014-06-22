/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_look_see.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 00:48:38 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 00:49:14 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void			look_north(int first, int seen, int *lvl_len, int *xy)
{
	if (seen == first)
	{
		xy[0] -= lvl_len[1];
		xy[1] += 1;
		lvl_len[0] += 1;
		lvl_len[1] += 2;
		return ;
	}
	xy[0]++;
}

t_square			*see(t_data *data, int cs, int seen, int *xyo, int *lvl_len)
{
	int				n;
	int				first;
	int				last;
	t_square		*square;

	square = get_square(data, xyo[0], xyo[1]);
	first = SQUARE(lvl_len[0]) - 1;
	n = data->fds[cs].player.level;
	last = (n + 1) * (n + 1) - 1;
	printf("square pos %i %i\n", square->x, square->y);
	if (seen == last)
		return (NULL);
	if (xyo[2] == N)
		look_north(first, seen, lvl_len, xyo);
	else if (xyo[2] == E)
		look_north(first, seen, lvl_len, xyo);
	else if (xyo[2] == S)
		look_north(first, seen, lvl_len, xyo);
	else if (xyo[2] == W)
		look_north(first, seen, lvl_len, xyo);
	return (square);
}
