/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:07:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/12 12:26:21 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <string.h>

static void	get_port(char *arg, t_data *data, char *name)
{
	if (arg)
		data->port = atoi(arg);
	else
		usage(name);
}
static void	init_opt(t_data *data)
{
	data->port = -1;
	data->x = -1;
	data->y = -1;
	data->teams = NULL;
	data->max_clients = -1;
	data->time = -1;
}

static void	check_opt(t_data *data, char *name)
{
	if (data->port == -1 || data->x == -1 || data->y == -1 || data->teams == NULL
		|| data->max_clients == -1 || data->time == -1)
		usage(name);
}

void		get_opt(char **argv, t_data *data)
{
	int		i;

	init_opt(data);
	i = 0;
	while (argv[++i])
	{
		if (!strcmp(argv[i], "-p"))
			get_port(argv[++i], data, argv[0]);
		else if (!strcmp(argv[i], "-x"))
			get_width(argv[++i], data, argv[0]);
		else if (!strcmp(argv[i], "-y"))
			get_height(argv[++i], data, argv[0]);
		else if (!strcmp(argv[i], "-n"))
			get_teams(argv, &i, data, argv[0]);
		else if (!strcmp(argv[i], "-c"))
			get_maxclients(argv[++i], data, argv[0]);
		else if (!strcmp(argv[i], "-t"))
			get_time(argv[++i], data, argv[0]);
		else
			usage(argv[0]);
	}
	check_opt(data, argv[0]);
}
