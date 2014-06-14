/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_enw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:51:01 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 17:33:04 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "enw #e #n X Y\n" - L’œuf a été pondu sur la case par le joueur.
*/

#include "server.h"
#include <stdio.h>

void	gui_enw(t_egg *egg, int cs)
{
	dprintf(cs, "enw #%d #%d %d %d\n", egg->id, egg->owner, egg->x, egg->y);
}
