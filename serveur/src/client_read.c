/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 13:34:32 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/13 15:01:25 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

void	client_read(t_data *data, int cs)
{
	int		blen;

	blen = strlen(data->fds[cs].buf_read);
	if (recv(cs, data->fds[cs].buf_read + blen, BUF_SIZE - blen, 0) <= 0)
	{
		close(cs);
		clean_fd(data->fds + cs);
		printf("client %d has disconnected\n", cs);
	}
	else if (data->fds[cs].buf_read[strlen(data->fds[cs].buf_read) - 1]
			 == '\n')
	{
		printf("%s", data->fds[cs].buf_read);
		bzero(data->fds[cs].buf_read, BUF_SIZE + 1);
	}
}
