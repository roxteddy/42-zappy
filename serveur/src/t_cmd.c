/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 19:51:46 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/20 22:02:05 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>

static t_cmd	new_command(char *cmd, void (*fct)(t_data *data, int cs,
												   char **cmd), int coef)
{
	t_cmd	c;

	c.cmd = strdup(cmd);
	c.fct = fct;
	c.coef = coef;
	return (c);
}

void			create_cmds(t_data *data)
{
	data->cmds[0] = new_command("avance", &cmd_forward, MOVE_T);
	data->cmds[1] = new_command("droite", &cmd_right, MOVE_T);
	data->cmds[2] = new_command("gauche", &cmd_left, MOVE_T);
	data->cmds[3] = new_command("voir", &cmd_look, LOOK_T);
	data->cmds[4] = new_command("inventaire", &cmd_invent, INV_T);
	data->cmds[5] = new_command("prend", &cmd_take, TAKE_T);
	data->cmds[6] = new_command("pose", &cmd_drop, DROP_T);
	data->cmds[7] = new_command("expulse", &cmd_push, PUSH_T);
	data->cmds[8] = new_command("broadcast", &cmd_bcast, BCAST_T);
	data->cmds[9] = new_command("incantation", &cmd_incant, INCANT_T);
	data->cmds[10] = new_command("fork", &cmd_fork, FORK_T);
	data->cmds[11] = new_command("connect_nbr", &cmd_max, 0);
}
