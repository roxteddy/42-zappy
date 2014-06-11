#include "client.h"

int		contains(char *needle, char **haystack, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (ft_strequ(needle, haystack[i]))
		{
			if (i != size - 1 && haystack[i + 1][0] != '-')
				return (1);
		}
		i++;
	}
	return (0);
}

int		check_args(int argc, char **argv)
{
	if (contains("-n", argv, argc) && contains("-p", argv, argc))
	{
		if (argc == 7 && contains("-h", argv, argc))
			return (1);
		else if (argc == 5)
			return (1);
	}
	return (0);
}

void	usage(void)
{
	ft_putendl("Usage: ./client -n <team> -p <port> [-h <hostname>]");
	ft_putendl(" -n nom d'equipe");
	ft_putendl(" -p port");
	ft_putendl(" -h nom de la machine [localhost]");
}

void	quit(int err)
{
	if (err == USAGE)
		usage();
	exit(err);
}

int		main(int argc, char **argv)
{
	if (check_args(argc, argv))
	{
		ft_putendl("ok");
	}
	else
		quit(USAGE);
	return (0);
}
