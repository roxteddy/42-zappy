/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:32:13 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/22 23:24:59 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ccmd_left(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player	*player;
    t_timeval	now;

	if (!(*t))
	{
		gettimeofday(&now, NULL);
		*t = (t_timeval*)malloc(sizeof(t_timeval));
		**t = time_add(data, &now, MOVE_T);
		return ;
	}
	(void)cmd;
	player = &data->fds[cs].player;
	if (--(player->o) == 0)
		player->o = 4;
	dprintf(cs, "ok\n");
	gui_broadcast(data, gui_ppo, player);
}
