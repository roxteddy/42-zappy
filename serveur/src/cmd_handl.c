/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 10:22:52 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/20 20:03:57 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

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
	printf("received cmd from client #%d : %s\n", cs, cmd);

	if (data->fds[cs].type == FD_CLIENT)
		client_handl(data, cmd, cs);
//	else if (data->fds[cs].type == FD_PLAYER)
//		player_handl(data, cmd, cs);
//	else if (data->fds[cs].type == FD_GUI)
//		gui_handl(data, cmd, cs);
}
