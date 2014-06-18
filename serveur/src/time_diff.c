/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 19:48:32 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/18 18:28:30 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/time.h>
typedef struct timeval		t_timeval;

int		time_diff(t_timeval *t1, t_timeval *t2)
{
	if (t2->tv_usec > t1->tv_usec)
		return (1);
	if (t2->tv_usec == t1->tv_usec)
		return (0);
	if (t2->tv_usec < t1->tv_usec)
		return (-1);
}
