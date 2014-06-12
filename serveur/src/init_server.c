/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 14:04:21 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/12 14:27:52 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <netdb.h>

void	init_server(t_data *data)
{
	struct sock_addr_in		sin;
	struct protoent			*proto;
	int						sock;

	if (!(proto = (struct protoent*)getprotobyname("tcp")))
        ft_error("getprotobyname");
    if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
        ft_error("socket");
	sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(data->port);
    if (bind(sock, (struct sockaddr*)&sin, sizeof(sin)) == -1)
        ft_error("bind");
    if (listen(sock, 42) == -1)
        ft_error("listen");
    data->fds[sock].type = FD_SERV;
    data->fds[sock].fct_read = srv_accept;
}
