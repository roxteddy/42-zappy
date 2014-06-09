/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfebvay <mfebvay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:57:59 by mfebvay           #+#    #+#             */
/*   Updated: 2014/06/04 09:18:12 by mfebvay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

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

typedef struct		s_cmd;
{
	char			*cmd;
	void			(*fct) (void);
}					t_cmd;

typedef struct      s_tlist
{
	char			*name;
	int				level;
	int				max_players;
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
}

typedef struct		s_data
{
	int				port;
	int				x;
	int				y;
	t_tlist			*teams;
	int				max_clients;
	int				time;
	t_square		**map;

}					t_data;

void	get_width(char *arg, t_opt *opt, char *name);
void	get_height(char *arg, t_opt *opt, char *name);
void	get_teams(char **argv, int *i, t_opt *opt, char *name);
void	get_maxclients(char *arg, t_opt *opt, char *name);
void	get_time(char *arg, t_opt *opt, char *name);
void	usage(char *str);

#endif
