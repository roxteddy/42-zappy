/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_plv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:17:38 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 16:19:38 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "plv #n L\n" "plv #n\n" Niveau d’un joueur.
*/

#include "server.h"
#include <stdlib.h>

void	cmd_plv(t_data *data, int cs, char **cmd)
{
	int		pid;

	if (cmd[1] && cmd[1][0] == '#')
		pid = atoi(cmd[1] + 1);
	gui_plv(data->fds[pid]->player, cs);
}
