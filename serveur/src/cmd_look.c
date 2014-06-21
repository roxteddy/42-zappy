/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:49:13 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/20 20:33:55 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>

static t_square		*see(t_data *data, int seen, int *x, int *y)
{
	t_square		*square;
	int				level;

	level = data->fds[cs].player.level;
	square = get_square(data, *x, *y);
	return (square);
}

void				cmd_look(t_data *data, int cs, char **cmd)
{
	t_square		*square;
	char			buf[BUF_SIZE];
	int				x;
	int				y;
	int				i;

	(void)cmd;
	memset(buf, '\0', BUF_SIZE);
	x = data->fds[cs].player.x;
	y = data->fds[cs].player.y;
	i = 0;
	while ((square = see(data, i, &x, &y)) != NULL)
	{
		dprintf(cs, "bct %d %d %d %d %d %d %d %d %d\n",
				square->x,
				square->y,
				square->food,
				square->linemate,
				square->deraumere,
				square->sibur,
				square->mendiane,
				square->phiras,
				square->thystame);
		i++;
	}
}
