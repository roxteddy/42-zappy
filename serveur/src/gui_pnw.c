/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pnw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:43:45 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 15:57:27 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gui_pnw(t_player *player, int cs)
{
	dprintf(cs, "pnw #%d %d %d %d %d %s\n", player->cs, player->x, player->y,
			player->o, player->level, player->team);
}
