/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 02:31:40 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 11:16:23 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	player_del(t_plist **list, t_player *player)
{
	t_plist	*current;
	t_plist	*tmp;

	current = *list;
	if (current->player == player)
	{
		*list = current->next;
		free(current);
	}
	else
	{
		while (current->next && current->next->player != player)
			current = current->next;
		tmp = current->next;
		current->next = current->next->next;
		free(tmp);
	}
}
