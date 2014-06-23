/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_incant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:37:09 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 03:48:50 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_plist			*get_players(t_data *data, t_player *player)
{
	(void)data;
	(void)player;
}

t_square		*check_square(t_data *data, t_player *player)
{
	t_square	*square;

	square = get_square(data, player->x, player->y);
	return (square);
}

void	ccmd_incant(t_data *data, int cs, char **cmd, t_timeval **t)
{
	(void)cmd;
	(void)t;
	t_player	*player;
	t_plist		*players;
	t_square	*square;

	player = &(data->fds[cs].player);
	if ((square = check_square(data, player)) == NULL)
	{
		;
	}
	players = get_players(data, player);
	(void)players;
}
