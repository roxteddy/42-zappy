/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_look_concat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 00:51:15 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 00:56:31 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>

static void		find_players(t_data *data, char *buf, t_square *square)
{
	(void)data;
	(void)buf;
	(void)square;
}

static void		add_elem(char *buf, int num, char *title)
{
	int			i;

	i = 0;
	while (i < num)
	{
		strcat(buf, " ");
		strcat(buf, title);
		i++;
	}
}

char			*concatenate(t_data *data, t_square *square)
{
	char		buf[BUF_SIZE];
	char		*str;

	memset(buf, '\0', BUF_SIZE);
	find_players(data, buf, square);
	add_elem(buf, square->food, "food");
	add_elem(buf, square->linemate, "linemate");
	add_elem(buf, square->deraumere, "deraumere");
	add_elem(buf, square->sibur, "sibur");
	add_elem(buf, square->mendiane, "mendiane");
	add_elem(buf, square->phiras, "phiras");
	add_elem(buf, square->thystame, "thystame");
	buf[BUF_SIZE - 1] = '\0';
	str = strdup(buf);
	return (str);
}
