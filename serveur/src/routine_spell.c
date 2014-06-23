/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_spell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 04:22:54 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 04:29:44 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	routine_spell(t_data *data)
{
	t_spell		*spell;
	t_timeval	now;

	gettimeofday(&now, NULL);
	spell = data->spells;
	while (spell)
	{
		if (time_diff(&spell->timer, &now) >= 0)
		{
			do_spell();
		}
		spell = spell->next;
	}
}
