/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:49:13 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/20 20:17:24 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>

static t_square		*see(t_data *data, int *seen, int level)
{
	t_square	*square;
	int			x;
	int			y;

	square = get_square(data, x, y);
	return (square);
}

void	cmd_look(t_data *data, int cs, char **cmd)
{
	t_square	**map;
	t_square	*square;
	char		buf[BUF_SIZE];
	int			i;
	int			level;

	(void)cmd;
	map = data->map;
	level = data->fds[cs].player.level;
	memset(buf, '\0', BUF_SIZE);
	i = 0;
	while ((square = see(data, &i, level)) != NULL)
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
	}
}
