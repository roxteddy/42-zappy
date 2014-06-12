/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:07:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/12 14:17:52 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <time.h>

//DEBUG
#include <stdio.h>

void	init_teams(t_data data)
{
	while (data.teams)
	{
		data.teams->level = 1;
		data.teams->max_players = data.max_clients;
		data.teams = data.teams->next;
	}
}

void	init_map(t_data *data)
{
	int		i;
	int		j;

	srand(time(NULL));
	if (!(data->map = (t_square**)malloc(sizeof(t_square*) * data->x)))
		ft_error();
	i = -1;
	while (++i < data->x)
	{
		if (!(data->map[i] = (t_square*)malloc(sizeof(t_square) * data->y)))
			ft_error();
		j = -1;
		while (++j < data->y)
		{
			data->map[i][j].food = rand() % 10;
			data->map[i][j].linemate = rand() % 10;
			data->map[i][j].deraumere = rand() % 10;
			data->map[i][j].sibur = rand() % 10;
			data->map[i][j].mendiane = rand() % 10;
			data->map[i][j].phiras = rand() % 10;
			data->map[i][j].thystame = rand() % 10;
// DEBUG
			dprintf(2, "Square %d-%d : food %d - linemate %d - deraumere %d - sibur %d - mendiane %d - phiras %d - thystame %d\n",
					i, j, data->map[i][j].food, data->map[i][j].linemate,
					data->map[i][j].deraumere, data->map[i][j].sibur, data->map[i][j].mendiane,
					data->map[i][j].phiras, data->map[i][j].thystame);
		}
	}
}

int		main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	init_data(&data);
	get_opt(argv, &data);
	init_teams(data);
	init_map(&data);
	init_server(&data);
	return (0);
}
