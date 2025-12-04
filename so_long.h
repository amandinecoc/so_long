/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:46:35 by acocoual          #+#    #+#             */
/*   Updated: 2025/12/04 10:43:29 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ************************************************************************** */
/*INCLUDES*/
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

/* ************************************************************************** */
/*DEFINE*/
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307

/* ************************************************************************** */
/*TYPEDEF*/
typedef enum e_status
{
	Success,
	You_win,
	Failure_nbr_arg,
	Failure_map,
	Failure_malloc,
	Failure_open,
}			t_status;

typedef struct s_solong
{
	char	**tab_map;
	char	**flood_fill_map;
	char	*ber_file;
	int		nbr_collectibles;
	int		nbr_exit;
	int		nbr_player;
	int		height;
	int		width;
	int		*exit;
	int		*player;
	int		mouv;
}			t_solong;

typedef struct s_mlx
{
	void		**assets;
	void		*img;
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_hooks
{
	t_solong	*data;
	t_mlx		*mlx_data;
}				t_hooks;

/* ************************************************************************** */
/*PARSING*/
int			parsing_so_long(t_solong *data, char **argv);
int			fill_data_struct(t_solong *data, char **argv);
int			initialize_data_struct(t_solong *data, char **argv);
int			create_tab_map_and_flood_fill_map(t_solong *data);
char		*create_map_in_line(int fd);
void		check_and_fill_nbr(t_solong *data);
void		print_error_or_success(int status);
void		free_all_data_struct(t_solong *data);
void		free_tab(char **tab);
int			check_caracters_of_map(t_solong *data);
int			check_square_and_borders_of_map(t_solong *data);
int			check_borders_of_map(t_solong *data);
int			check_flood_fill_map(t_solong *data);
int			flood_fill_map(t_solong *data, int x, int y);

/* ************************************************************************** */
/*SO_LONG*/
void tab_player(t_solong *data);
void movement(t_solong *data, char map, int x, int y);
void key_left(t_solong *data);
// void key_right(t_solong *data);
void key_down(t_solong *data);
void key_high(t_solong *data);

#endif