/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:40:26 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 17:43:16 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "sgt T\n" "sst T\n" Modification de l’unité de temps sur le serveur.
*/

#include "server.h"
#include <stdlib.h>

void	cmd_sst(t_data *data, int cs, char **cmd)
{

	if (cmd[1])
		data->time = atoi(cmd[1]);
// FONCTION MODIFIANTE > LE SGT DOIT ETRE BROADCAST A TOUS LES GUI
	gui_sgt(data, cs);
}
