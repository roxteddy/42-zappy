/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 08:22:25 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/10 15:45:06 by fcorre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <string.h>

void	tlist_add(t_tlist **teams, char *name)
{
	t_tlist		*new;

	if ((new = (t_tlist*)malloc(sizeof(*new))) == NULL)
		ft_error();
	new->name = strdup(name);
	if (*teams)
	{
		new->next = *teams;
		*teams = new;
	}
	else
	{
		new->next = NULL;
		*teams = new;
	}
}
