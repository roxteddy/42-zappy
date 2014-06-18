#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "client.h"



int		check_host_opt(char **tab)
{
	if (!strcmp(tab[1], "-n") && !strcmp(tab[3], "-p") && !strcmp(tab[5], "-h"))
		return (init_args(tab[6], tab[2], atoi(tab[4])));
	if (!strcmp(tab[1], "-n") && !strcmp(tab[5], "-p") && !strcmp(tab[3], "-h"))
		return (init_args(tab[4], tab[2], atoi(tab[6])));
	if (!strcmp(tab[1], "-p") && !strcmp(tab[3], "-n") && !strcmp(tab[5], "-h"))
		return (init_args(tab[6], tab[4], atoi(tab[2])));
	if (!strcmp(tab[1], "-p") && !strcmp(tab[5], "-n") && !strcmp(tab[3], "-h"))
		return (init_args(tab[4], tab[6], atoi(tab[2])));
	if (!strcmp(tab[1], "-h") && !strcmp(tab[3], "-p") && !strcmp(tab[5], "-n"))
		return (init_args(tab[2], tab[6], atoi(tab[4])));
	if (!strcmp(tab[1], "-h") && !strcmp(tab[5], "-p") && !strcmp(tab[3], "-n"))
		return (init_args(tab[2], tab[4], atoi(tab[6])));
	return (0);
}

int		check_args(int argc, char **argv)
{
	if (argc == 5)
	{
 		if (!strcmp(argv[1], "-n") && !strcmp(argv[3], "-p"))
			return (init_args("localhost", argv[2], atoi(argv[4])));
		else if (!strcmp(argv[1], "-p") && !strcmp(argv[3], "-n"))
			return (init_args("localhost", argv[4], atoi(argv[2])));
		return (0);
	}
	else if (argc == 7)
	{
		if (!strcmp(argv[1], "-n") && !strcmp(argv[3], "-p") && !strcmp(argv[5], "-h"))
			return (check_host_opt(argv));
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (check_args(argc, argv))
	{
		printf("ok");
	}
	else
		quit(USAGE);
	return (0);
}
