/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:46:35 by acocoual          #+#    #+#             */
/*   Updated: 2025/12/04 05:05:13 by amandine         ###   ########.fr       */
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
	int		len_i;
	int		len_j;
	int		*exit;
	int		*player;
	int		mouv;
}			t_solong;

/* ************************************************************************** */
/*PARSING*/
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
int			check_borders_of_map(t_solong *data, int len_i, int len_j);

/* ************************************************************************** */
/*SO_LONG*/

#endif