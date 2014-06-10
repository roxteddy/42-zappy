/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:07:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/04 08:30:02 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

static void	get_port(char *arg, t_opt *opt, char *name)
{
	if (arg)
		opt->port = atoi(arg);
	else
		usage(name);
}
static void	init_opt(t_opt *opt)
{
	opt->port = -1;
	opt->x = -1;
	opt->y = -1;
	opt->teams = NULL;
	opt->max_clients = -1;
	opt->time = -1;
}

static void	check_opt(t_opt *opt, char *name)
{
	if (opt->port == -1 || opt->x == -1 || opt->y == -1 || opt->teams == NULL
		|| opt->max_clients == -1 || opt->time == -1)
		usage(name);
}

void		get_opt(char **argv, t_opt *opt)
{
	int		i;

	init_opt(opt);
	i = 0;
	while (argv[++i])
	{
		if (!strcmp(argv[i], "-p"))
			get_port(argv[++i], opt, argv[0]);
		else if (!strcmp(argv[i], "-x"))
			get_width(argv[++i], opt, argv[0]);
		else if (!strcmp(argv[i], "-y"))
			get_height(argv[++i], opt, argv[0]);
		else if (!strncmp(argv[i], "-n"))
			get_teams(argv, &i, opt, argv[0]);
		else if (!strncmp(argv[i], "-c"))
			get_maxclients(argv[++i], opt, argv[0]);
		else if (!strcmp(argv[i], "-t"))
			get_time(argv[++i], opt, argv[0]);
		else
			usage(argv[0]);
	}
	check_opt(opt, argv[0]);
}
