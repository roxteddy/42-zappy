/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_food.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 19:09:21 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/18 19:47:16 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	check_food(t_data *data, t_player *player)
{
	struct timeval	*step;

	step = time_add(data, player->food_t, FOOD_T);
	if (time_diff(gettimeofday(), step) >= 0)
	{
		player->food--;
		player->food_t = step;
	}
}

void		routine_food(t_data *data)
{
	t_team	team;
	t_plist	plist;

	team = data->teams;
	while (team)
	{
		plist = team->list;
		while (plist)
		{
			check_food(data, plist->player);
			plist = plist->next;
		}
		team = team->next;
	}
}
