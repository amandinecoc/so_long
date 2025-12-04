/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:08:16 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 14:40:44 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_high(t_hooks *hooks)
{
	int	x;
	int	y;

	tab_player(hooks->data);
	x = hooks->data->player[0];
	y = hooks->data->player[1];
	movement(hooks, &hooks->data->tab_map[x - 1][y], x, y);
	if (hooks->data->tab_map[x - 1][y] == 'E'
		&& hooks->data->nbr_collectibles != 0)
	{
		hooks->data->exit[0] = x - 1;
		hooks->data->exit[1] = y;
		hooks->data->tab_map[x][y] = '0';
		hooks->data->tab_map[x - 1][y] = 'P';
		print_mouv(hooks->data);
	}
}

void	key_down(t_hooks *hooks)
{
	int	x;
	int	y;

	tab_player(hooks->data);
	x = hooks->data->player[0];
	y = hooks->data->player[1];
	movement(hooks, &hooks->data->tab_map[x + 1][y], x, y);
	if (hooks->data->tab_map[x + 1][y] == 'E'
		&& hooks->data->nbr_collectibles != 0)
	{
		hooks->data->exit[0] = x + 1;
		hooks->data->exit[1] = y;
		hooks->data->tab_map[x][y] = '0';
		hooks->data->tab_map[x + 1][y] = 'P';
		print_mouv(hooks->data);
	}
}

void	key_right(t_hooks *hooks)
{
	int	x;
	int	y;

	tab_player(hooks->data);
	x = hooks->data->player[0];
	y = hooks->data->player[1];
	movement(hooks, &hooks->data->tab_map[x][y + 1], x, y);
	if (hooks->data->tab_map[x][y + 1] == 'E'
		&& hooks->data->nbr_collectibles != 0)
	{
		hooks->data->exit[0] = x;
		hooks->data->exit[1] = y + 1;
		hooks->data->tab_map[x][y] = '0';
		hooks->data->tab_map[x][y + 1] = 'P';
		print_mouv(hooks->data);
	}
}

void	key_left(t_hooks *hooks)
{
	int	x;
	int	y;

	tab_player(hooks->data);
	x = hooks->data->player[0];
	y = hooks->data->player[1];
	movement(hooks, &hooks->data->tab_map[x][y - 1], x, y);
	if (hooks->data->tab_map[x][y - 1] == 'E'
		&& hooks->data->nbr_collectibles != 0)
	{
		hooks->data->exit[0] = x;
		hooks->data->exit[1] = y - 1;
		hooks->data->tab_map[x][y] = '0';
		hooks->data->tab_map[x][y - 1] = 'P';
		print_mouv(hooks->data);
	}
}

void	movement(t_hooks *hooks, char *map, int x, int y)
{
	if (*map == '0')
	{
		hooks->data->tab_map[x][y] = '0';
		*map = 'P';
		print_mouv(hooks->data);
		if (hooks->data->exit[0] == x && hooks->data->exit[1] == y)
			hooks->data->tab_map[x][y] = 'E';
	}
	if (*map == 'C')
	{
		hooks->data->tab_map[x][y] = '0';
		*map = 'P';
		print_mouv(hooks->data);
		hooks->data->nbr_collectibles--;
		if (hooks->data->exit[0] == x && hooks->data->exit[1] == y)
			hooks->data->tab_map[x][y] = 'E';
	}
	if (*map == 'E' && hooks->data->nbr_collectibles == 0)
	{
		print_mouv(hooks->data);
		free_all_data_struct(hooks->data);
		print_error_or_success(You_win, hooks->data);
		close_wind(hooks, Success);
	}
}
