/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:37:40 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 02:19:20 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

static void timer_init(t_data *data, t_timeval **timer, t_player *player)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	*timer = (t_timeval*)malloc(sizeof(t_timeval));
	**timer = time_add(data, &now, DROP_T);
	gui_broadcast(data, gui_pfk, player);
}

void	ccmd_fork(t_data *data, int cs, char **cmd, t_timeval **t)
{
    t_player    *player;
	t_egg		*egg;
	t_timeval	now;
	t_tlist		*team;

	gettimeofday(&now, NULL);
	(void)cmd;
    player = &data->fds[cs].player;
    if (!(*t))
        timer_init(data, t, player);
    else
    {
		egg = (t_egg*)malloc(sizeof(t_egg));
		egg->id = data->egg_nb++;
		egg->owner = cs;
		egg->team = strdup(player->team);
		egg->food = 10;
		egg->food_t = now;
		egg->birth = time_add(data, &now, BIRTH_T);
		egg->x = player->x;
		egg->y = player->y;
		egg->o = player->o;
		egg->next = data->eggs;
		data->eggs = egg;
		team = data->teams;
		while (team)
		{
			if (!strcmp(team->name, player->team))
			{
				team->slots++;
				break ;
			}
			team = team->next;
		}
		gui_broadcast(data, gui_enw, egg);
		dprintf(cs, "ok\n");
	}
}
