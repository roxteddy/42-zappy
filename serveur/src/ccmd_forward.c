/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:30:49 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/22 23:04:10 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ccmd_forward(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player	*player;

	if (!(*t))
	{
		*t = (t_timeval*)malloc(sizeof(t_timeval));
		return ;
	}
	(void)cmd;
	player = &data->fds[cs].player;
	if (player->o == N)
		player->y = (player->y - 1) % data->y;
	else if (player->o == S)
		player->y = (player->y + 1) % data->y;
	else if (player->o == W)
		player->x = (player->x - 1) % data->x;
	else if (player->o == E)
		player->x = (player->x + 1) % data->x;
	dprintf(cs, "ok\n");
	gui_broadcast(data, gui_ppo, player);
}
