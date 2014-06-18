/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:24:38 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 16:26:49 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void    gui_pin(t_player *player, int cs)
{
    dprintf(cs, "pin #%d %d %d %d %d %d %d %d %d %d\n", player->cs, player->x,
			player->y, player->food, player->linemate, player->deraumere,
			player->sibur, player->mendiane, player->phiras, player->thystame);
}
