/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_bcast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:36:27 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 11:37:38 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

static void	find(t_data *data, t_player *origin, t_player *target, int *r)
{
	r[0] = pathfinder(data, get_square(data, origin->x, origin->y),
			get_square(data, target->x, target->y - 1));
	r[1] = pathfinder(data, get_square(data, origin->x, origin->y),
			get_square(data, target->x - 1, target->y - 1));
	r[2] = pathfinder(data, get_square(data, origin->x, origin->y),
			get_square(data, target->x - 1, target->y));
	r[3] = pathfinder(data, get_square(data, origin->x, origin->y),
			get_square(data, target->x - 1, target->y + 1));
	r[4] = pathfinder(data, get_square(data, origin->x, origin->y),
			get_square(data, target->x, target->y + 1));
	r[5] = pathfinder(data, get_square(data, origin->x, origin->y),
			get_square(data, target->x + 1, target->y + 1));
	r[6] = pathfinder(data, get_square(data, origin->x, origin->y),
			get_square(data, target->x + 1, target->y));
	r[7] = pathfinder(data, get_square(data, origin->x, origin->y),
			get_square(data, target->x + 1, target->y - 1));
}

static int	direction(int dir, t_player *target)
{
	if (dir && target->o == E)
		return ((dir + 1) % 8 + 1);
	if (dir && target->o == S)
		return ((dir + 3) % 8 + 1);
	if (dir && target->o == W)
		return ((dir + 5) % 8 + 1);
	return (dir);
}

static void	bcast(t_data *data, t_player *origin, t_player *target)
{
	int		dir;
	int		r[8];
	int		i;
	int		len;

	if (origin->x == target->x && origin->y == target->y)
		dir = 0;
	else
	{
		find(data, origin, target, r);
		i = 0;
		dir = 1;
		len = r[i];
		while (++i < 8)
		{
			if (r[i] < len)
			{
				len = r[i];
				dir = i + 1;
			}
		}
	}
	dir = direction(dir, target);
	dprintf(target->cs, "message %d,%s\n", dir, origin->msg);
}

static void	timer_init(t_data *data, t_timeval **timer)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	*timer = (t_timeval*)malloc(sizeof(t_timeval));
	**timer = time_add(data, &now, BCAST_T);
}

void		ccmd_bcast(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_tlist		*team;
	t_plist		*plist;
	t_player	*player;

	player = &data->fds[cs].player;
	if (!(*t))
		timer_init(data, t);
	else
	{
		player->msg = split_join(cmd + 1);
		gui_broadcast(data, gui_pbc, player);
		team = data->teams;
		while (team)
		{
			plist = team->list;
			while (plist)
			{
				if (plist->player != player)
					bcast(data, player, plist->player);
				plist = plist->next;
			}
			team = team->next;
		}
		dprintf(cs, "ok\n");
	}
}
