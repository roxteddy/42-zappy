/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_invent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:09:37 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 10:55:02 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

static void		concat(char *buf, t_player *player)
{
	memset(buf, '\0', BUF_SIZE);
	strcat(buf, "{nourriture ");
	strcat(buf, ft_itoa(player->food));
	strcat(buf, ", linemate ");
	strcat(buf, ft_itoa(player->linemate));
	strcat(buf, ", deraumere ");
	strcat(buf, ft_itoa(player->deraumere));
	strcat(buf, ", sibur ");
	strcat(buf, ft_itoa(player->sibur));
	strcat(buf, ", mendiane ");
	strcat(buf, ft_itoa(player->mendiane));
	strcat(buf, ", thystame ");
	strcat(buf, ft_itoa(player->thystame));
	strcat(buf, "}");
}

void			ccmd_invent(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_player	*player;
	char		buf[BUF_SIZE];
	t_timeval	now;

	if (!(*t))
	{
		gettimeofday(&now, NULL);
		*t = (t_timeval*)malloc(sizeof(t_timeval));
		**t = time_add(data, &now, MOVE_T);
		return ;
	}
	(void)cmd;
	player = &(data->fds[cs].player);
	concat(buf, player);
	dprintf(cs, "%s\n", buf);
}
