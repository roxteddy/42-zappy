/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:07:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/13 14:04:16 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	get_port(char *arg, t_data *data)
{
	if (arg)
		data->port = atoi(arg);
	else
		usage(data->name);
}

void	get_width(char *arg, t_data *data)
{
	if (arg)
		data->x = atoi(arg);
	else
		usage(data->name);
}

void	get_height(char *arg, t_data *data)
{
	if (arg)
		data->y = atoi(arg);
	else
		usage(data->name);
}

void	get_teams(char **argv, int *i, t_data *data)
{
	while (argv[++(*i)] && argv[*i][0] != '-')
		team_add(data, argv[*i]);
	*i -= 1;
}

void	get_maxclients(char *arg, t_data *data)
{
	if (arg)
		data->max_clients = atoi(arg);
	else
		usage(data->name);
}

void	get_time(char *arg, t_data *data)
{
	if (arg)
		data->time = atoi(arg);
	else
		usage(data->name);
}
