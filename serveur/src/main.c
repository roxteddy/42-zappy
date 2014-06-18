/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:07:28 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/18 18:54:18 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	init_data(&data, av);
	//
	printf("DATA INIT OK\n");
	init_server(&data);
	//
	printf("SERVER INIT OK\n");
	while ("loop")
	{
		init_fd(&data);
		data.sel = select(data.fd_nb + 1, &data.fd_read, &data.fd_write,
				NULL, &data.timeout);
		check_fd(&data);
	}
	return (0);
}
