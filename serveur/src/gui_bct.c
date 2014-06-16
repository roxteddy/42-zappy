/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_bct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:32:15 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/16 19:10:47 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gui_bct(t_square *square, int cs)
{
	dprintf(cs, "bct %d %d %d %d %d %d %d %d %d\n",
			square->x,
			square->y,
			square->food,
			square->linemate,
			square->deraumere,
			square->sibur,
			square->mendiane,
			square->phiras,
			square->thystame);
}
