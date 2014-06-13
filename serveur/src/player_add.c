/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 16:10:46 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/13 16:18:03 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		player_add(t_data *data, char *team, t_player *player)
{
	t_tlist	*current;
	t_plist	*new;

	current = data->team;
	while (current && strcmp(current->name, team))
		current = current->next;
	if (current)
	{
		new = (t_plist*)malloc(sizeof(t_plist));
		new->player = player;
		new->next = current->list;
		current->list = new;
		return (1);
	}
	else
		return (-1);
}
