/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_food.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 19:09:21 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/20 22:51:54 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/time.h>

static void	check_food(t_data *data, t_player *player, t_timeval *now)
{
	t_timeval	step;

	step = time_add(data, &player->food_t, FOOD_T);
	if (time_diff(&step, now) >= 0)
	{
		player->food--;
		player->food_t = step;
	}
}

void		routine_food(t_data *data)
{
	t_tlist		*team;
	t_plist		*plist;
	t_timeval	now;

	gettimeofday(&now, NULL);
	team = data->teams;
	while (team)
	{
		plist = team->list;
		while (plist)
		{
			check_food(data, plist->player, &now);
			plist = plist->next;
		}
		team = team->next;
	}
}
