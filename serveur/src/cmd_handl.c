/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 10:22:52 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/16 19:25:49 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

static void		join_team(t_data *data, char *cmd, int cs)
{
	t_tlist		*teams;

	teams = data->teams;
	while (teams && strcmp(teams->name, cmd))
		teams = teams->next;
	if (teams)
	{
		if (teams->slots)
		{
			data->fds[cs].type = FD_PLAYER;
			dprintf(cs, "%d\n", --(teams->slots));
			player_init(data, teams, cs);
			dprintf(cs, "%d %d\n", data->x, data->y);
		}
		else
			dprintf(cs, "no slot available\n");
	}
	else
		dprintf(cs, "no such team\n");
}

static void		client_handl(t_data *data, char *cmd, int cs)
{
	if (!strcmp(cmd, "GRAPHIC"))
	{
		printf("New GUI connected\n");
		data->fds[cs].type = FD_GUI;
		gui_init(data, cs);
	}
	else
	{
		printf("New player connected\n");
		join_team(data, cmd, cs);
	}
}

void			cmd_handl(t_data *data, char *cmd, int cs)
{
	printf("%s\n", cmd);
	send(cs, "cmd received\n", 13, 0);

	if (data->fds[cs].type == FD_CLIENT)
		client_handl(data, cmd, cs);
//	else if (data->fds[cs].type == FD_PLAYER)
//		player_handl(data, cmd, cs);
//	else if (data->fds[cs].type == FD_GUI)
//		gui_handl(data, cmd, cs);
}
