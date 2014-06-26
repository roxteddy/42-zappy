/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 03:48:38 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/26 04:01:07 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int		get_player_nb(t_data *data, t_player *player)
{
    int         nb;
    t_tlist     *team;
    t_plist     *list;

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

int			spell_check(t_data *data, t_player *player)
{
	int			player_nb;
    t_square	*square;

	square = get_square(data, player->x, player->y);
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
