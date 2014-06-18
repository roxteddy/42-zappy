/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pdr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:24:42 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 17:27:10 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pdr #n i\n" - Le joueur jette une ressource.
*/

#include "server.h"
#include <stdio.h>

void	gui_pdr(t_player *player, int cs)
{
	dprintf(cs, "pdr #%d %d\n", player->cs, player->drop);
}
