/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_mct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 16:43:43 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 16:47:48 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gui_mct(t_data *data, int cs)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->x)
	{
		j = -1;
		while(++j < data->y)
			gui_bct(&data->map[i][j], int cs);
	}
}
