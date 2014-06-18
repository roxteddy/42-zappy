/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 14:09:54 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/18 18:50:54 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <time.h>

static void		check_opt(t_data *data)
{
//DEBUG
	printf("port %d - x %d - y %d - teams %p - max client %d - time %d\n", data->port, data->x, data->y, data->teams, data->max_clients, data->time);

	if (data->port == -1 || data->x == -1 || data->y == -1
		  || data->teams == NULL || data->max_clients == -1 || data->time == -1)
		usage(data->name);
}

static void		get_opt(t_data *data, char **av)
{
	int		i;

	i = 0;
	while (av[++i])
	{
		if (!strcmp(av[i], "-p"))
			get_port(av[++i], data);
		else if (!strcmp(av[i], "-x"))
			get_width(av[++i], data);
		else if (!strcmp(av[i], "-y"))
			get_height(av[++i], data);
		else if (!strcmp(av[i], "-n"))
			get_teams(av, &i, data);
		else if (!strcmp(av[i], "-c"))
			get_maxclients(av[++i], data);
		else if (!strcmp(av[i], "-t"))
			get_time(av[++i], data);
		else
			usage(av[0]);
	}
	check_opt(data);
}

static void		init_teams(t_data *data)
{
	t_tlist		*current;

	current = data->teams;
	while (current)
	{
		current->slots = data->max_clients;
		current->list = NULL;
		current = current->next;
	}
}

static void		init_map(t_data *data)
{
	int		i;
	int		j;

	srand(time(NULL));
	if (!(data->map = (t_square**)malloc(sizeof(t_square*) * data->x)))
		perror(data->name);
	i = -1;
	while (++i < data->x)
	{
		if (!(data->map[i] = (t_square*)malloc(sizeof(t_square) * data->y)))
			perror(data->name);
		j = -1;
		while (++j < data->y)
		{
			data->map[i][j].x = i;
			data->map[i][j].y = j;
			data->map[i][j].food = rand() % 10;
			data->map[i][j].linemate = rand() % 10;
			data->map[i][j].deraumere = rand() % 10;
			data->map[i][j].sibur = rand() % 10;
			data->map[i][j].mendiane = rand() % 10;
			data->map[i][j].phiras = rand() % 10;
			data->map[i][j].thystame = rand() % 10;
		}
	}
}

void			init_data(t_data *data, char **av)
{
	struct rlimit	rlp;
	int				i;

	data->name = av[0];
	data->port = -1;
	data->x = -1;
	data->y = -1;
	data->teams = NULL;
	data->eggs = NULL;
	data->max_clients = -1;
	data->time = -1;
	data->map = NULL;
	if (getrlimit(RLIMIT_NOFILE, &rlp) == -1)
		error(av[0]);
	data->max_fd = rlp.rlim_cur;
	if (!(data->fds = (t_fd*)malloc(sizeof(*data->fds) * data->max_fd)))
		error(av[0]);
	i = -1;
	while (++i < data->max_fd)
		clean_fd(data->fds + i);
	get_opt(data, av);
	init_teams(data);
	init_map(data);
	data->timeout.tv_sec = TIMEOUT_S;
	data->timeout.tv_usec = TIMEOUT_US;
}
