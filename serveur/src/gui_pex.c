/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:53:10 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 16:57:02 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pex #n\n" - Un joueur expulse
*/

#include "server.h"
#include <stdio.h>

void	gui_pex(t_player *player, int cs)
{
	dprintf(cs, "pex #%d\n", player->cs);
}
