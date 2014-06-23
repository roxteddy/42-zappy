/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_incant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:37:09 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 04:31:44 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <sys/time.h>

t_plist			*get_players(t_data *data, t_player *player, t_spell *spell)
{
	t_plist	*plist;
	t_tlist	*team;
	t_plist	*list;

	team = data->teams;
	while (team)
	{
		list = team->list;
		while (list)
		{
			if (list->player->x == player->x && list->player->y == player->y
				&& list->player->level == player->level)
			{
				player_add(&plist, list->player);
				list->player->spell = spell;
				dprintf(list->player->cs, "elevation en cours\n");
			}
			list = list->next;
		}
		team = team->next;
	}
	return (plist);
}

int				get_player_nb(t_data *data, t_player *player)
{
	int		nb;
	t_tlist	*team;
	t_plist	*list;

	nb = 0;
	team = data->teams;
	while (team)
	{
		list = team->list;
		while (list)
		{
			if (list->player->x == player->x && list->player->y == player->y
				&& list->player->level == player->level)
				nb++;
			list = list->next;
		}
		team = team->next;
	}
	return (nb);
}

int				check_req(t_data *data, t_player *player, t_square *square)
{
	int	player_nb;

	player_nb = get_player_nb(data, player);
	if (player_nb >= data->spell_tab[player->level - 1][0]
		&& square->linemate >= data->spell_tab[player->level - 1][1]
		&& square->deraumere >= data->spell_tab[player->level - 1][2]
		&& square->sibur >= data->spell_tab[player->level - 1][3]
		&& square->mendiane >= data->spell_tab[player->level - 1][4]
		&& square->phiras >= data->spell_tab[player->level - 1][5]
		&& square->thystame >= data->spell_tab[player->level - 1][6])
		return (1);
	else
		return (0);
}

int		check_square(t_data *data, t_player *player)
{
	t_square	*square;
	square = get_square(data, player->x, player->y);
		if (check_req(data, player, square))
			return (1);
		else
			return (0);
}

void	ccmd_incant(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player	*player;
	t_spell		*spell;
	t_timeval	now;

	(void)cmd;
	(void)t;
	gettimeofday(&now, NULL);
	player = &(data->fds[cs].player);
	if (check_square(data, player))
		dprintf(cs, "ko\n");
	else
	{
		spell = (t_spell*)malloc(sizeof(t_spell));
		spell->x = player->x;
		spell->y = player->y;
		spell->owner = player;
		spell->plist = get_players(data, player, spell);
		spell->timer = time_add(data, &now, INCANT_T);
		spell->next = data->spells;
		data->spells = spell;
		gui_broadcast(data, gui_pic, spell);
	}
}
