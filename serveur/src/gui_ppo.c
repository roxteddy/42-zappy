/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_ppo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:11:16 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 16:15:02 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gui_ppo(t_player *player, int cs)
{
	dprintf(cs, "ppo #%d %d %d %d\n", player->cs, player->x, player->y,
            player->o);
}
