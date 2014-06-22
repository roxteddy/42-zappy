/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcmd_bct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:15:47 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/22 22:09:36 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

void	gcmd_bct(t_data *data, int cs, char **cmd)
{
	int		x;
	int		y;

	if ((!cmd[1] || (x = atoi(cmd[1]) >= data->x)) ||
		(!cmd[2] || (y = atoi(cmd[2]) >= data->y)))
		dprintf(cs, "error\n");
	else
		gui_bct(&data->map[x][y], cs);
}
