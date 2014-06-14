/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_pie.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:20:20 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 17:21:47 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** "pie X Y R\n" - Fin de l’incantation sur la case donnée avec le
** résultat R (0 ou 1).
*/

void	gui_pie(t_spell *spell, int cs)
{
	dprintf(cs, "pie %d %d %d\n", spell->x, spell->y, spell->success);
}
