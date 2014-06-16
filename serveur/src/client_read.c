/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 13:34:32 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/16 19:17:37 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

static char  *strsub(char *str, int start, int len)
{
    char    *sub;

    sub = (char *)malloc(sizeof(char) * (len + 1));
    strncpy(sub, str + start, len);
    sub[len] = '\0';
    return (sub);
}

static void	bufread_handl(t_data *data, char *str, int cs)
{
	int		i;
	int		len;
	char	*cmd;

	i = 0;
	while (str[i])
	{
		len = 0;
		while (str[i + len] && str[i + len] != '\n')
			len++;
		if (str[i + len])
		{
			cmd = strsub(str, i, len);
			cmd_handl(data, cmd, cs);
			free(cmd);
			i += len + 1;
			len = 0;
		}
		if (!str[i + len])
		{
			strncpy(str, str + i, BUF_SIZE);
			return ;
		}
	}
}

void	client_read(t_data *data, int cs)
{
	int		blen;

	blen = strlen(data->fds[cs].buf_read);
	if (recv(cs, data->fds[cs].buf_read + blen, BUF_SIZE - blen, 0) <= 0)
	{
		close(cs);
		clean_fd(data->fds + cs);
		printf("client %d has disconnected\n", cs);
	}
	else if (data->fds[cs].buf_read[strlen(data->fds[cs].buf_read) - 1]
			 == '\n')
		bufread_handl(data, data->fds[cs].buf_read, cs);
}
