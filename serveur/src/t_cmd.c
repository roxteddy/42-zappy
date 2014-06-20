/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 19:51:46 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/20 20:17:27 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "string.h"

//
void	cmd_forward(t_data *data, int cs, char **cmd);
void	cmd_right(t_data *data, int cs, char **cmd);
void	cmd_left(t_data *data, int cs, char **cmd);
void	cmd_look(t_data *data, int cs, char **cmd);
void	cmd_take(t_data *data, int cs, char **cmd);
void	cmd_drop(t_data *data, int cs, char **cmd);
void	cmd_push(t_data *data, int cs, char **cmd);
void	cmd_bcast(t_data *data, int cs, char **cmd);
void	cmd_incant(t_data *data, int cs, char **cmd);
void	cmd_fork(t_data *data, int cs, char **cmd);
void	cmd_max(t_data *data, int cs, char **cmd);

t_cmd	new_command(char *cmd, void (*fct)(t_data *data, int cs, char **cmd))
{
	t_cmd	c;

	c.cmd = strdup(cmd);
	c.fct = fct;
	return (c);
}

void	create_cmds(t_data *data)
{
	data->cmds[0] = new_command("avance", &cmd_forward);
	data->cmds[1] = new_command("droite", &cmd_right);
	data->cmds[2] = new_command("gauche", &cmd_left);
	data->cmds[3] = new_command("voir", &cmd_look);
	data->cmds[4] = new_command("inventaire", &cmd_invent);
	data->cmds[5] = new_command("prend", &cmd_take);
	data->cmds[6] = new_command("pose", &cmd_drop);
	data->cmds[7] = new_command("expulse", &cmd_push);
	data->cmds[8] = new_command("broadcast", &cmd_bcast);
	data->cmds[9] = new_command("incantation", &cmd_incant);
	data->cmds[10] = new_command("fork", &cmd_fork);
	data->cmds[11] = new_command("connect_nbr", &cmd_max);
}
