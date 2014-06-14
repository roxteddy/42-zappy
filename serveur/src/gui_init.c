/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:00:55 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 15:54:26 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	gui_init(t_data *data, int cs)
{
	cmd_msz(data, cs);
	cmd_sgt(data, cs);
	cmd_mct(data, cs);
	cmd_tna(data, cs);
	gui_plist(data, cs);
	gui_elist(data, cs);
}
