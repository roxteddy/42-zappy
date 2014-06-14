/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_sgt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:37:47 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 17:38:53 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "sgt T\n" "sgt\n" Demande de l’unité de temps courante sur le serveur
*/

#include "server.h"
#include <stdio.h>

void	gui_sgt(t_data *data, int cs)
{
	dprintf(cs, "sgt %d\n", data->time);
}
