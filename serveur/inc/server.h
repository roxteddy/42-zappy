/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:57:59 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/14 13:35:59 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define FD_FREE    0
# define FD_SERV    1
# define FD_CLIENT  2
# define FD_PLAYER	3
# define FD_GUI		4

# define BUF_SIZE	1024
# define TIMEOUT_S	3
# define TIMEOUT_US	0

# define N			1
# define E			2
# define S			3
# define W			4

# include <sys/select.h>

//DEBUG
# include <stdio.h>

typedef struct		s_egg
{
	int				id;
	char			*team;
	int				food;
	int				x;
	int				y;
	int				o;
	struct s_egg	*next;
}					t_egg;

typedef struct		s_player
{
	char			*team;
	int				cs;
	int				x;
	int				y;
	int				o;
	int				level;
	int				food;
	int				linemate;
	int				deraumere;
	int				sibur;
	int				mendiane;
	int				phiras;
	int				thystame;
}					t_player;

typedef struct		s_plist
{
	t_player		*player;
	struct s_plist	*next;
}					t_plist;

typedef struct      s_fd
{
	int				type;
	void			(*fct_read)();
	void			(*fct_write)();
	char			buf_read[BUF_SIZE + 1];
	char			buf_write[BUF_SIZE + 1];
	t_player		player;
}                   t_fd;

typedef struct		s_cmd
{
	char			*cmd;
	void			(*fct) (void);
}					t_cmd;

typedef struct		s_tlist
{
	char			*name;
	int				slots;
	t_plist			*list;
	struct s_tlist	*next;
}					t_tlist;

typedef struct		s_square
{
	int				food;
	int				linemate;
	int				deraumere;
	int				sibur;
	int				mendiane;
	int				phiras;
	int				thystame;
}					t_square;

typedef struct		s_data
{
	char			*name;
	int				port;
	int				x;
	int				y;
	t_tlist			*teams;
	t_egg			*eggs;
	int				max_clients;
	int				time;
	t_square		**map;
	int				fd_nb;
	int				max_fd;
	t_fd			*fds;
	int				sel;
	fd_set			fd_read;
	fd_set			fd_write;
	struct timeval	timeout;
}					t_data;

/*
t_cmd				cmd[] = {	{"avance", &cmd_forward},
								{"droite", &cmd_right},
								{"gauche", &cmd_left},
								{"voir", &cmd_look},
								{"inventaire", &cmd_invent},
								{"prend", &cmd_take},
								{"pose", &cmd_drop},
								{"expulse", &cmd_push},
								{"broadcast", &cmd_bcast},
								{"incantation", &cmd_incant},
								{"fork", &cmd_fork},
								{"connect_nbr", &cmd_max}	};
*/
void	check_fd(t_data *data);
void    clean_fd(t_fd *fd);
void	client_read(t_data *data, int cs);
void	client_write(t_data *data, int cs);
void    cmd_handl(t_data *data, char *cmd, int cs);
void    egg_del(t_egg **list, t_egg *egg);
void	error(char *str);
void	get_height(char *arg, t_data *data);
void	get_maxclients(char *arg, t_data *data);
void    get_port(char *arg, t_data *data);
void	get_teams(char **argv, int *i, t_data *data);
void	get_time(char *arg, t_data *data);
void	get_width(char *arg, t_data *data);
void	init_data(t_data *data, char **av);
void	init_fd(t_data *data);
void	init_server(t_data *data);
void    player_add(t_plist **plist, t_player *player);
void	player_init(t_data *data, t_tlist *team, int cs);
void    srv_accept(t_data *data, int sock);
void	team_add(t_data *data, char *name);
void	usage(char *str);

#endif
