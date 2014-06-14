/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_edi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:36:19 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 17:37:18 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "edi #e\n" - L’œuf éclos est mort de faim.
*/

#include "server.h"
#include <stdio.h>

void	gui_edi(t_egg *egg, int cs)
{
	dprintf(cs, "edi #%d\n", egg->id);
}
