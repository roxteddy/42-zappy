#include <stdlib.h>
#include <string.h>
#include "client.h"


int		port(int num)
{
	static int	init = 0;
	static int	val = 0;

	if (init)
		return (val);
	if (num < 1 || num > 65535)
		quit(PORT);
	val = num;
	init = 1;
	return (val);
}

char	*team(char *name)
{
	static int	init = 0;
	static char	*val = 0;

	if (init)
		return (val);
	val = strdup(name);
	init = 1;
	return (val);
}

char	*ft_host(char *host)
{
	static int	init = 0;
	static char	*val = 0;

	if (init)
		return (val);
	val = strdup(host);
	init = 1;
	return (val);
}

t_data	*set_data(char *host, char *name, int num)
{
	static t_data	*data = 0;
	static int		init = 0;

	if (init)
		return (data);
	if (num < 1 || num > 65535)
		quit(PORT);
	data = malloc(sizeof(t_data));
	data->team = name;
	data->host = host;
	data->port = num;
	init = 1;
	return (data);
}

t_data	*get_data(void)
{
	return (set_data(0, 0, 0));
}

int		init_args(char *host, char *name, int number)
{
	team(name);
	ft_host(host);
	port(number);
	set_data(host, name, number);
	return (1);
}
