/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:13:30 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/20 19:49:35 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

void		routine_action(t_data *data)
{
	int			i;
	t_player	*player;

	i = -1;
	while (++i < data->max_fd)
	{
		if (data->fds[i].type == FD_CLIENT)
		{
			player = &data->fds[i].player;
			if (player->actions && timediff(player->actions->timer,
											gettimeofday()) >= 0)
			{
				player->actions->action(data, i, player->actions->cmd);
				action_delfirst(&player->actions);
			}
		}
	}
}
