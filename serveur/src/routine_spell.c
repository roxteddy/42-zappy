/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_spell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 04:22:54 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 09:05:24 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void	disperse_linemate(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][1];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->linemate += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].linemate -= 1;
	}
}

void	disperse_deraumere(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][2];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->deraumere += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].deraumere -= 1;
	}
}

void	disperse_sibur(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][3];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->sibur += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].sibur -= 1;
	}
}

void	disperse_mendiane(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][4];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->mendiane += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].mendiane -= 1;
	}
}

void	disperse_phiras(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][5];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->phiras += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].phiras -= 1;
	}
}

void	disperse_thystame(t_data *data, t_spell *spell)
{
	int			i;
	t_square	*target;

	i = data->spell_tab[spell->level - 1][6];
	while (i--)
	{
		target = get_square(data, rand() % data->x, rand() % data->y);
		target->thystame += 1;
		gui_broadcast(data, gui_bct, target);
		data->map[spell->x][spell->y].thystame -= 1;
	}
}

void	disperse(t_data *data, t_spell *spell)
{
	srand(time(NULL));
	disperse_linemate(data, spell);
	disperse_deraumere(data, spell);
	disperse_sibur(data, spell);
	disperse_mendiane(data, spell);
	disperse_phiras(data, spell);
	disperse_thystame(data, spell);
	gui_broadcast(data, gui_bct, get_square(data, spell->x, spell->y));
}

void	do_spell(t_data *data, t_spell *spell)
{
	t_plist	*plist;

//check success
	spell->success = 1;
	gui_broadcast(data, gui_pie, spell);
	plist = spell->plist;
	while (plist)
	{
		dprintf(plist->player->cs, "niveau actuel : %d\n",
				plist->player->level + spell->success);
		gui_broadcast(data, gui_plv, plist->player);
		plist = plist->next;
	}
	if (spell->success)
		disperse(data, spell);
}

void	routine_spell(t_data *data)
{
	t_spell		*spell;
	t_timeval	now;

//
//	printf("starting spell routine\n");
	gettimeofday(&now, NULL);
	spell = data->spells;
	while (spell)
	{
		if (time_diff(&spell->timer, &now) >= 0)
		{
			do_spell(data, spell);
			spell_del(&data->spells, spell);
			routine_spell(data);
			return ;
		}
		spell = spell->next;
	}
//
//	printf("ending spell routine\n");
}
