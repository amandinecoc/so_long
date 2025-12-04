/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:14:07 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 10:56:09 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_wind(t_solong *data, t_mlx *mlx_data, int i, int j)
{
	while (data->tab_map[i])
	{
		j = 0;
		while (data->tab_map[i][j])
		{
			if (data->tab_map[i][j] == '1')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[0], j * 32, i * 32);
			if (data->tab_map[i][j] == '0')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[1], j * 32, i * 32);
			if (data->tab_map[i][j] == 'E')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[2], j * 32, i * 32);
			if (data->tab_map[i][j] == 'P')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[3], j * 32, i * 32);
			if (data->tab_map[i][j] == 'C')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[4], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	initialize_assets(t_mlx *mlx_data)
{
	int	height;
	int	width;

	height = 32;
	width = 32;
	mlx_data->assets[0] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assests/Wall.xpm", &width, &height);
	mlx_data->assets[1] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Floor.xpm", &width, &height);
	mlx_data->assets[2] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Exit.xpm", &width, &height);
	mlx_data->assets[3] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Player.xpm", &width, &height);
	mlx_data->assets[4] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Collectibles.xpm", &width, &height);
}

void	movement_key(int key, t_solong *data, t_hooks *hooks)
{
	if (key == ESC_KEY)
		// close
	else if (key == W_KEY) key_high(data);
	else if (key == S_KEY)
		key_down(data);
	else if (key == D_KEY)
		key_right(data);
	else if (key == A_KEY)
		key_left(data);
	initialize_wind(hooks->data, hooks->mlx_data, 0, 0);
}

void	mlx_game(t_solong *data)
{
	t_mlx mlx_data;
	t_hooks hooks;

	hooks.data = data;
	hooks.mlx_data = &mlx_data;
}