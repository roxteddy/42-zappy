/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:13:30 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/20 22:34:50 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/time.h>

void		routine_action(t_data *data)
{
	t_tlist		*team;
	t_plist		*list;
	t_timeval	now;

	gettimeofday(&now, NULL);
	team = data->teams;
	while (team)
	{
		list = team->list;
		while (list)
		{
			if (list->player->actions
				&& time_diff(&list->player->actions->timer, &now) >= 0)
            {
                list->player->actions->action(data, list->player->cs,
											  list->player->actions->cmd);
                action_delfirst(&list->player->actions);
            }
			list = list->next;
		}
		team = team->next;
	}
	(void)now;
}
