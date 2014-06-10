/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:07:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/10 15:50:50 by fcorre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_teams(t_opt data)
{
	while (data.teams)
	{
		data.teams->level = 1;
		data.teams->max_players = opt.max_clients;
		data.teams = opt.teams->next;
	}
}

int		main(int argc, char **argv)
{
	t_data	data;
	int		i;

	get_opt(argv, &data);
	init_teams(data);
	if ((data.map = (t_square**)malloc(sizeof(t_square*) * data.x)) == NULL)
		ft_error();
	i = -1;
	while (++i < data.x)
		if (!(data.map[i] = (t_square*)malloc(sizeof(t_square) * data.y)))
			ft_error();
}
