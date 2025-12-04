/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:46:35 by acocoual          #+#    #+#             */
/*   Updated: 2025/12/04 02:50:28 by amandine         ###   ########.fr       */
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
	int		*exit;
	int		*player;
	int		mouv;
}			t_solong;

/* ************************************************************************** */
/*PARSING*/

/* ************************************************************************** */
/*SO_LONG*/

#endif