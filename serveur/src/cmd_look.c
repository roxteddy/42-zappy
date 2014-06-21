/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:49:13 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/21 21:28:40 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>
#include <stdlib.h>

static t_square		*look_east(int first, int last, int seen, int *xy);
static t_square		*look_south(int first, int last, int seen, int *xy);
static t_square		*look_west(int first, int last, int seen, int *xy);

static t_square		*look_north(int first, int last, int seen, int *xy)
{
	t_square		*square;

	if (seen == last)
		return (NULL);
	if (seen == first)
	{
		(void)xy;
	}
	return (square);
}

static t_square		*see(t_data *data, int cs, int seen, int *xy, int o)
{
	int				n;
	int				first;
	int				last;

	n = data->fds[cs].player.level + 1;
	first = (n * (n + 1) * (2 * n + 1)) / 6;
	last = (n - 1) * (n - 1) - 1;
	if (o == N)
		return (look_north(first, last, seen, xy));
	else if (o == E)
		return (look_east(first, last, seen, xy));
	else if (o == S)
		return (look_south(first, last, seen, xy));
	else if (o == W)
		return (look_west(first, last, seen, xy));
	return (NULL);
}

void				cmd_look(t_data *data, int cs, char **cmd)
{
	t_square		*square;
	char			buf[BUF_SIZE];
	int				*xy;
	int				i;

	(void)cmd;
	memset(buf, '\0', BUF_SIZE);
	xy = (int *)malloc(sizeof(int) * 2);
	xy[0] = data->fds[cs].player.x;
	xy[1] = data->fds[cs].player.y;
	i = 0;
	while ((square = see(data, cs, i, xy, data->fds[cs].player.o)) != NULL)
	{
		/*
		   square->food,
		   square->linemate,
		   square->deraumere,
		   square->sibur,
		   square->mendiane,
		   square->phiras,
		   square->thystame);
		   */
		i++;
	}
	free(xy);
}
