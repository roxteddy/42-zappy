/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_look.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 22:45:53 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/22 23:47:38 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>
#include <stdlib.h>

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

static t_square		*see(t_data *data, int cs, int seen, int *xyo, int *lvl_len)
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

static void			find_players(t_data *data, char *buf, t_square *square)
{
	(void)data;
	(void)buf;
	(void)square;
}

static void			add_elem(char *buf, int num, char *title)
{
	int				i;

	i = 0;
	while (i < num)
	{
		strcat(buf, " ");
		strcat(buf, title);
		i++;
	}
}

static char			*concatenate(t_data *data, t_square *square)
{
	char			buf[BUF_SIZE];
	char			*str;

	memset(buf, '\0', BUF_SIZE);
	find_players(data, buf, square);
	add_elem(buf, square->food, "food");
	add_elem(buf, square->linemate, "linemate");
	add_elem(buf, square->deraumere, "deraumere");
	add_elem(buf, square->sibur, "sibur");
	add_elem(buf, square->mendiane, "mendiane");
	add_elem(buf, square->phiras, "phiras");
	add_elem(buf, square->thystame, "thystame");
	buf[BUF_SIZE - 1] = '\0';
	str = strdup(buf);
	return (str);
}

static void			send(int cs, char **strings, int len)
{
	int				i;
	char			buf[BUF_SIZE];

	memset(buf, '\0', BUF_SIZE);
	strcat(buf, "{");
	i = 0;
	while (i < len)
	{
		if (strings[i])
		{
			strcat(buf, strings[i]);
			strcat(buf, ",");
			free(strings[i]);
		}
		i++;
	}
	strcat(buf, "}");
	dprintf(cs, "%s\n", buf);
}

void				ccmd_look(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player		*player;
	t_square		*square;
	//char			*strings[SQUARE(data->fds[cs].player.level + 1)];
	char			*strings[SQUARE(3 + 1)];
	int				xyo[3];
	int				i;
	int				level_len[2];

	player = &data->fds[cs].player;
	player->level = 3;
	(void)cmd;
	(void)t; // if null init/quit else do (ccmd drop)
	xyo[0] = player->x;
	xyo[1] = player->y;
	xyo[2] = player->o;
//DEBUG
	printf("player ptr: %p\n", player);
	printf("player #%i - pos : %i %i\n", cs, player->x, player->y);
	i = 0;
	level_len[0] = 1;
	level_len[1] = 1;
	while ((square = see(data, cs, i, xyo, level_len)) != NULL)
	{
		strings[i] = concatenate(data, square);
		i++;
	}
	send(cs, strings, SQUARE(data->fds[cs].player.level + 1) - 1);
}
