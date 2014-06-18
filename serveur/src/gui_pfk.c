/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pfk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:22:22 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 17:23:56 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pfk #n\n" - Le joueur pond un œuf
*/

#include "server.h"
#include <stdio.h>

void	gui_pfk(t_player *player, int cs)
{
	dprintf(cs, "pfk #%d\n", player->cs);
}
