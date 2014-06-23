/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 06:55:56 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 08:32:52 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

void	pathfill(t_data *data, int **map, t_square *square, int count)
{
	int		x;
	int		y;

	x = square->x;
	y = square->y;
	if (map[x][y] > count)
	{
		map[x][y] = count;
		pathfill(data, map, get_square(data, x, y - 1), count + 1);
		pathfill(data, map, get_square(data, x - 1, y - 1), count + 1);
		pathfill(data, map, get_square(data, x - 1, y), count + 1);
		pathfill(data, map, get_square(data, x - 1, y + 1), count + 1);
		pathfill(data, map, get_square(data, x, y + 1), count + 1);
		pathfill(data, map, get_square(data, x + 1, y + 1), count + 1);
		pathfill(data, map, get_square(data, x + 1, y), count + 1);
		pathfill(data, map, get_square(data, x + 1, y + 1), count + 1);
	}
}

int		pathfinder(t_data *data, t_square *origin, t_square *target)
{
	int		map[data->x][data->y];
	int		i;

	i = -1;
	while (++i < data->x)
		memset(map[i], INT_MAX, data->y);
	pathfill(data, (int**)map, get_square(data, origin->x, origin->y), 0);
	return (map[target->x][target->y]);
}
