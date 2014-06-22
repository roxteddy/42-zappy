/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:32:13 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/22 06:41:47 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_left(t_data *data, int cs, char **cmd)
{
	t_player	*player;

	(void)cmd;
	player = &data->fds[cs].player;
	if (--(player->o) == 0)
		player->o = 4;
	dprintf(cs, "ok\n");
	gui_broadcast(data, gui_ppo, player);
}
