/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 06:55:56 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 09:48:24 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

// DEBUG
void	print_map(t_data *data, int **map)
{
	int i;
	int j;

	i = -1;
	while (++i < data->x)
	{
		j = -1;
		while (++j < data->y)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

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
		print_map(data, map);
	}
}

int		pathfinder(t_data *data, t_square *origin, t_square *target)
{
	int		**map;
	int		i;
	int		j;

	map = (int **)malloc(sizeof(int*) * data->x);
	i = -1;
	while (++i < data->x)
	{
		map[i] = (int*)malloc(sizeof(int) * data->y);
		j = -1;
		while (++j < data->y)
			map[i][j] = (data->x > data->y) ? data->x : data->y;
	}
	pathfill(data, map, get_square(data, origin->x, origin->y), 0);
	return (map[target->x][target->y]);
}
