/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:57:48 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/20 20:11:04 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;

	tmp = (char *)malloc((len + 1) * sizeof(char));
	strncpy(tmp, s + start, len);
	tmp[len] = '\0';
	return (tmp);
}
