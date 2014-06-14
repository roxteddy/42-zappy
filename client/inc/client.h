#ifndef CLIENT_H
# define CLIENT_H

# define USAGE		-1
# define PORT		-2

typedef struct		s_data
{
	char			*host;
	char			*team;
	int				port;
}					t_data;

void				quit(int err);
int					init_args(char *host, char *name, int number);

#endif
