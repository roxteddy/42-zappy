/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcmd_msz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:33:12 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/22 22:14:47 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	gcmd_msz(t_data *data, int cs, char **cmd)
{
	(void)data;
	(void)cmd;
	gui_msz(NULL, cs);
}
