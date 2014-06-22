/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_ppo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:11:16 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/22 06:24:34 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gui_ppo(void *param, int cs)
{
	t_player	*player;

	player = (t_player*)param;
	dprintf(cs, "ppo #%d %d %d %d\n", player->cs, player->x, player->y,
            player->o);
}
