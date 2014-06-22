/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:32:13 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/22 23:00:21 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ccmd_left(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player	*player;

//need timer handl
	(void)t;
	(void)cmd;
	player = &data->fds[cs].player;
	if (--(player->o) == 0)
		player->o = 4;
	dprintf(cs, "ok\n");
	gui_broadcast(data, gui_ppo, player);
}
