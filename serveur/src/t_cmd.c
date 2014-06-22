/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 19:51:46 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/22 22:06:13 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>

static t_cmd	new_command(char *cmd,
							void (*fct)(t_data *data, int cs, char **cmd,
										t_timeval *timer), int coef)
{
	t_cmd	c;

	c.cmd = strdup(cmd);
	c.fct = fct;
	c.coef = coef;
	return (c);
}

void			create_cmds(t_data *data)
{
	data->cmds[0] = new_command("avance", &ccmd_forward, MOVE_T);
	data->cmds[1] = new_command("droite", &ccmd_right, MOVE_T);
	data->cmds[2] = new_command("gauche", &ccmd_left, MOVE_T);
	data->cmds[3] = new_command("voir", &ccmd_look, LOOK_T);
	data->cmds[4] = new_command("inventaire", &ccmd_invent, INV_T);
	data->cmds[5] = new_command("prend", &ccmd_take, TAKE_T);
	data->cmds[6] = new_command("pose", &ccmd_drop, DROP_T);
	data->cmds[7] = new_command("expulse", &ccmd_push, PUSH_T);
	data->cmds[8] = new_command("broadcast", &ccmd_bcast, BCAST_T);
	data->cmds[9] = new_command("incantation", &ccmd_incant, INCANT_T);
	data->cmds[10] = new_command("fork", &ccmd_fork, FORK_T);
	data->cmds[11] = new_command("connect_nbr", &ccmd_max, 0);
}
