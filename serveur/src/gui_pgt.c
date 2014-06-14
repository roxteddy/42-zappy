/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pgt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:27:45 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 17:29:21 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pgt #n i\n" - Le joueur prend une ressource.
*/

#include "server.h"
#include <stdio.h>

void	gui_pgt(t_player *player, int cs)
{
	dprintf(cs, "pgt #%d %d\n", player->cs, player->get);
}
