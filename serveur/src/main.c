/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:07:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/12 17:11:25 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_teams(t_data data)
{
	while (data.teams)
	{
		data.teams->level = 1;
		data.teams->max_players = data.max_clients;
		data.teams = data.teams->next;
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
