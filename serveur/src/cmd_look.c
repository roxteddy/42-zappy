/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 19:49:13 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/20 22:05:32 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>

static t_square		*see(t_data *data, int *seen, int level)
{
	t_square	*square;
	int			x = 0;
	int			y = 0;
//
	(void)seen;
	(void)level;
	square = get_square(data, x, y);
	return (square);
}

void	cmd_look(t_data *data, int cs, char **cmd)
{
	t_square	*square;
	char		buf[BUF_SIZE];
	int			i;
	int			level;

	(void)cmd;
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
