/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 19:37:00 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/23 09:06:27 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	check_fd(t_data *data)
{
	int		i;

//
//	printf("starting fd check\n");
	i = -1;
	while (++i < data->max_fd && data->sel > 0)
	{
		if (FD_ISSET(i, &data->fd_read))
			data->fds[i].fct_read(data, i);
		if (FD_ISSET(i, &data->fd_write))
			data->fds[i].fct_write(data, i);
		if (FD_ISSET(i, &data->fd_read) || FD_ISSET(i, &data->fd_write))
			data->sel--;
	}
//
//	printf("ending fd check\n");
}
