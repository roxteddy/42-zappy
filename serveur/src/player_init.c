/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 11:17:51 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 13:35:32 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <strings.h>
#include <stdlib.h>
#include <time.h>

static void		player_place_egg(t_data *data, t_egg *egg, t_player *player)
{
	player->x = egg->x;
	player->y = egg->y;
	player->o = egg->o;
	egg_del(&data->eggs, egg);
	//GUI MSG
}

static void		player_place_new(t_data *data, t_player *player)
{
	srand(time(NULL));
	player->x = rand() % data->x;
	player->y = rand() % data->y;
	player->o = rand() % 4 + 1;
	//GUI MSG
}

static void		player_place(t_data *data, t_tlist *team, t_player *player)
{
	t_egg	*egg;
	t_egg	*current;

	egg = NULL;
	current = data->eggs;
	while (current)
	{
		if (!strcmp(current->team, team->name) && (!egg || current->food < egg->food))
			egg = current;
		current = current->next;
	}
	if (egg)
		player_place_egg(data, egg, player);
	else
		player_place_new(data, player);
}

void			player_init(t_data *data, t_tlist *team, int cs)
{
	t_player	*player;

	player = &data->fds[cs].player;
	player->team = strdup(team->name);
	player->cs = cs;
	player->level = 1;
	player->food = 10;
	player->linemate = 0;
	player->deraumere = 0;
    player->sibur = 0;
    player->mendiane = 0;
    player->phiras = 0;
    player->thystame = 0;
	player_place(data, team, player);
	player_add(&team->list, player);
}
