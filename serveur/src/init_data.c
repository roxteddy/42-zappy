/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 14:09:54 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/12 14:18:46 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <sys/resource.h>

void    init_data(t_data *data)
{
	struct rlimit	rlp;
	int				i;

	data->port = -1;
	data->x = -1;
	data->y = -1;
	data->teams = NULL;
	data->max_clients = -1;
	data->time = -1;
	data->map = NULL;
	if (getrlimit(RLIMIT_NOFILE, &rlp) == -1)
		ft_error("getrlimit");
	data->max_fd = rlp.rlim_cur;
	if (!(data->fds = (t_fd*)malloc(sizeof(*data->fds) * data->max_fd)))
		ft_error("malloc");
	i = -1;
	while (++i < data->max_fd)
		clean_fd(data->fds + i);
}
