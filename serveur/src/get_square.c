/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 20:02:25 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/20 20:07:06 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_square	*get_square(t_data *data, int x, int y)
{
	t_square	*square;

	x %= data->x;
	y %= data->y;
	square = &data->map[x][y];
	return (square);
}
