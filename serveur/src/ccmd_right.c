/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:31:21 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/22 23:01:44 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_right(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player	*player;

//need timer handl
	(void)t;
	(void)cmd;
	player = &data->fds[cs].player;
	player->o = (player->o % 4) + 1;
	dprintf(cs, "ok\n");
	gui_broadcast(data, gui_ppo, player);
}
