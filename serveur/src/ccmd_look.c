/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccmd_look.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 22:45:53 by pciavald          #+#    #+#             */
/*   Updated: 2014/06/23 00:53:34 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

static void			send(int cs, char **strings, int len)
{
	int				i;
	char			buf[BUF_SIZE];

	dprintf(cs, "{");
	i = 0;
	while (i < len)
	{
		memset(buf, '\0', BUF_SIZE);
		if (strings[i])
		{
			strcat(buf, strings[i]);
			strcat(buf, ",");
			dprintf(cs, "%s", buf);
			//free(strings[i]);
		}
		i++;
	}
	dprintf(cs, "}");
}

static void			timer_init(t_data *data, t_timeval **timer)
{
	t_timeval		now;

	gettimeofday(&now, NULL);
	*timer = (t_timeval*)malloc(sizeof(t_timeval));
	**timer = time_add(data, &now, DROP_T);
}

void	orient(int o)
{
	if (o == N)
		printf("N\n");
	if (o == S)
		printf("S\n");
	if (o == E)
		printf("E\n");
	if (o == W)
		printf("W\n");
}

void				ccmd_look(t_data *data, int cs, char **cmd, t_timeval **t)
{
	t_square		*square;
	char			*strings[SQUARE(data->fds[cs].player.level + 1)];
	int				xyo[3];
	int				i;
	int				level_len[2];

	(void)cmd;
	if (*t == NULL)
		timer_init(data, t);
	else
	{
		xyo[0] = data->fds[cs].player.x;
		xyo[1] = data->fds[cs].player.y;
		xyo[2] = data->fds[cs].player.o;
		orient(xyo[2]);
		i = 0;
		level_len[0] = 1;
		level_len[1] = 1;
		while ((square = see(data, cs, i, xyo, level_len)) != NULL)
			strings[i++] = concatenate(data, square);
		send(cs, strings, SQUARE(data->fds[cs].player.level + 1) - 1);
	}
}
