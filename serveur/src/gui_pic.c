/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:01:50 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/16 19:12:56 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pic X Y L #n #n …\n" - Premier joueur lance l’incantation pour tous les
** suivants sur la case
*/

#include "server.h"
#include <stdio.h>

void	gui_pic(t_spell *spell, int cs)
{
	t_plist	*plist;

	dprintf(cs, "pic %d %d %d #%d", spell->x, spell->y, spell->level,
			spell->owner->cs);
	plist = spell->plist;
	while (plist)
	{
		dprintf(cs, " #%d", plist->player->cs);
		plist = plist->next;
	}
	dprintf(cs, "\n");
}
