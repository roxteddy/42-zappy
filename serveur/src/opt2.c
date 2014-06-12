/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:07:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/12 12:29:10 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

void	get_width(char *arg, t_data *data, char *name)
{
	if (arg)
		data->x = atoi(arg);
	else
		usage(name);
}

void	get_height(char *arg, t_data *data, char *name)
{
	if (arg)
		data->y = atoi(arg);
	else
		usage(name);
}

void	get_teams(char **argv, int *i, t_data *data, char *name)
{
	while (argv[++(*i)] && argv[*i][0] != '-')
		tlist_add(&data->teams, argv[*i]);
	*i -= 1;
	(void)name;
}

void	get_maxclients(char *arg, t_data *data, char *name)
{
	if (arg)
		data->max_clients = atoi(arg);
	else
		usage(name);
}

void	get_time(char *arg, t_data *data, char *name)
{
	if (arg)
		data->time = atoi(arg);
	else
		usage(name);
}
