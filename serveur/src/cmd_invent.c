/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_invent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:09:37 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/20 19:55:37 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>
#include <stdio.h>

void	cmd_invent(t_data *data, int cs, char **cmd)
{
	t_player	player;
	char		buf[BUF_SIZE];

	(void)cmd;
	player = data->fds[cs].player;
	memset(buf, '\0', BUF_SIZE);
	strcat(buf, "{nourriture ");
	strcat(buf, ft_itoa(player.food));
	strcat(buf, ", linemate ");
	strcat(buf, ft_itoa(player.linemate));
	strcat(buf, ", deraumere ");
	strcat(buf, ft_itoa(player.deraumere));
	strcat(buf, ", sibur ");
	strcat(buf, ft_itoa(player.sibur));
	strcat(buf, ", mendiane ");
	strcat(buf, ft_itoa(player.mendiane));
	strcat(buf, ", thystame ");
	strcat(buf, ft_itoa(player.thystame));
	strcat(buf, "}");
	dprintf(cs, "%s\n", buf);
}
