/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_ebo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:34:59 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/16 19:10:56 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "ebo #e\n" - Un joueur s’est connecté pour l’œuf
*/
#include "server.h"

void	gui_ebo(t_egg *egg, int cs)
{
	dprintf(cs, "ebo #%d\n", egg->id);
}
