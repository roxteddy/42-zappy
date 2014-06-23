/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_look_concat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 00:51:15 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 02:20:55 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>

static int		add_elem(char *buf, int num, char *title)
{
	int			i;

	i = 0;
	while (i < num)
	{
		strcat(buf, " ");
		strcat(buf, title);
		i++;
	}
	return (num);
}

static int		find_players(t_data *data, int cs, char *buf, t_square *square)
{
	t_tlist		*team;
	t_plist		*list;
	t_player	*player;
	int			ret;

	ret = 0;
	team = data->teams;
	while (team)
	{
		list = team->list;
		while (list)
		{
			player = list->player;
			if ((player->x == square->x && player->y == square->y)
					&& player->cs != cs)
				ret += add_elem(buf, 1, "player");
			list = list->next;
		}
		team = team->next;
	}
	return (ret);
}

char			*concatenate(t_data *data, int cs, t_square *square)
{
	char		buf[BUF_SIZE];
	char		*str;
	int			ret;

	memset(buf, '\0', BUF_SIZE);
	ret = 0;
	ret += find_players(data, cs, buf, square);
	ret += add_elem(buf, square->food, "food");
	ret += add_elem(buf, square->linemate, "linemate");
	ret += add_elem(buf, square->deraumere, "deraumere");
	ret += add_elem(buf, square->sibur, "sibur");
	ret += add_elem(buf, square->mendiane, "mendiane");
	ret += add_elem(buf, square->phiras, "phiras");
	ret += add_elem(buf, square->thystame, "thystame");
	buf[BUF_SIZE - 1] = '\0';
	if (ret == 0)
		buf[0] = ' ';
	str = strdup(buf);
	return (str);
}
