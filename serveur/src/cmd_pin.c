/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:22:17 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 16:23:58 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pin #n X Y q q q q q q q\n" "pin #n\n" Inventaire d’un joueur.
*/

#include "server.h"
#include <stdlib.h>

void	cmd_pin(t_data *data, int cs, char **cmd)
{
	int		pid;

	if (cmd[1] && cmd[1][0] == '#')
		pid = atoi(cmd[1] + 1);
	gui_pin(data->fds[pid]->player, cs);
}
