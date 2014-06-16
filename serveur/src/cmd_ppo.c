/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ppo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:03:07 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/16 19:09:20 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "ppo #n X Y O\n" "ppo #n\n" Position d’un joueur.
*/

#include "server.h"
#include <stdlib.h>

void	cmd_ppo(t_data *data, int cs, char **cmd)
{
	int			pid;

	if (cmd[1] && cmd[1][0] == '#')
		pid = atoi(cmd[1] + 1);
	gui_ppo(&data->fds[pid].player, cs);
}
