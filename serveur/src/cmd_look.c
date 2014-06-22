/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:49:13 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/22 06:28:05 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>
#include <stdlib.h>


//definition temporaire des fonctions
static t_square		*look_east(int first, int seen, int *xy)
{
	(void)first;
	(void)seen;
	(void)xy;
	return ((t_square*)1);
}
static t_square		*look_south(int first, int seen, int *xy)
{
	(void)first;
	(void)seen;
	(void)xy;
	return ((t_square*)1);
}
static t_square		*look_west(int first, int seen, int *xy)
{
	(void)first;
	(void)seen;
	(void)xy;
	return ((t_square*)1);
}

static void			look_north(int first, int seen, int *len, int *xy)
{
	if (seen == first)
	{
		xy[0] -= *len;
		xy[1] += 1;
		*len += 2;
		return ;
	}
	xy[0]++;
}

static t_square		*see(t_data *data, int cs, int seen, int *xyo, int *len)
{
	int				n;
	int				first;
	int				last;
	t_square		*square;

	square = get_square(data, xyo[0], xyo[1]);
	n = data->fds[cs].player.level + 1;
	first = (n * (n + 1) * (2 * n + 1)) / 6;
	last = (n - 1) * (n - 1) - 1;
	if (seen == last)
		return (NULL);
	if (xyo[2] == N)
		look_north(first, seen, len, xyo);
	else if (xyo[2] == E)
		look_east(first, seen, xyo);
	else if (xyo[2] == S)
		look_south(first, seen, xyo);
	else if (xyo[2] == W)
		look_west(first, seen, xyo);
	return (square);
}

static void			find_players(t_data *data, char *buf, t_square *square)
{
	(void)data;
	(void)buf;
	(void)square;
}

static char			*concatenate(t_data *data, t_square *square)
{
	char			buf[BUF_SIZE];
	char			*str = "";

	(void)square;
		/*
		   square->food,
		   square->linemate,
		   square->deraumere,
		   square->sibur,
		   square->mendiane,
		   square->phiras,
		   square->thystame);
		   */
	memset(buf, '\0', BUF_SIZE);
	strcat(buf, "{");
	find_players(data, buf, square);
//str was undefined
	return (str);
}

static void			send(char **strings, int len)
{
	int				i;

	i = 0;
	while (i < len)
	{
		(void)strings;
		i++;
	}
}

void				cmd_look(t_data *data, int cs, char **cmd)
{
	t_square		*square;
	char			*strings[SQUARE(data->fds[cs].player.level)];
	int				*xyo;
	int				i;
	int				len;

	(void)cmd;
	xyo = (int *)malloc(sizeof(int) * 3);
	xyo[0] = data->fds[cs].player.x;
	xyo[1] = data->fds[cs].player.y;
	xyo[2] = data->fds[cs].player.o;
	i = 0;
	len = 1;
	while ((square = see(data, cs, i, xyo, &len)) != NULL)
	{
		strings[i] = concatenate(data, square);
		i++;
	}
	free(xyo);
	send(strings, SQUARE(data->fds[cs].player.level));
}
