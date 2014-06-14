#include <stdio.h>
#include <stdlib.h>
#include "client.h"

void	quit(int err)
{
	if (err == USAGE)
	{
		fprintf(stderr, "Usage: ./client -n <team> -p <port> [-h <hostname>]\n");
		fprintf(stderr, "\t-n nom d'equipe\n\t-p port\n");
		fprintf(stderr, "\t-h nom de la machine [localhost]\n");
	}
	else if (err == PORT)
		fprintf(stderr, "Port invalide\n");
	exit(err);
}
