/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:14:07 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 12:41:03 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_wind(t_hooks *hooks)
{
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->img);
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[0]);
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[1]);
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[2]);
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[3]);
	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[4]);
	mlx_destroy_window(hooks->mlx_data->mlx, hooks->mlx_data->win);
	mlx_destroy_display(hooks->mlx_data->mlx);
	free(hooks->mlx_data->mlx);
	free(hooks->mlx_data->assets);
	exit(EXIT_SUCCESS);
}

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
												"assets/Wall.xpm",
												&width,
												&height);
	mlx_data->assets[1] = mlx_xpm_file_to_image(mlx_data->mlx,
												"assets/Floor.xpm",
												&width,
												&height);
	mlx_data->assets[2] = mlx_xpm_file_to_image(mlx_data->mlx,
												"assets/Exit.xpm",
												&width,
												&height);
	mlx_data->assets[3] = mlx_xpm_file_to_image(mlx_data->mlx,
												"assets/Player.xpm",
												&width,
												&height);
	mlx_data->assets[4] = mlx_xpm_file_to_image(mlx_data->mlx,
												"assets/Collectibles.xpm",
												&width,
												&height);
}

int	movement_key(int keycode, t_hooks *hooks)
{
	if (keycode == ESC_KEY)
	{
		free_all_data_struct(hooks->data);
		print_error_or_success(game_escape, hooks->data);
		close_wind(hooks);
	}
	else if (keycode == W_KEY)
		key_high(hooks);
	else if (keycode == S_KEY)
		key_down(hooks);
	else if (keycode == D_KEY)
		key_right(hooks);
	else if (keycode == A_KEY)
		key_left(hooks);
	initialize_wind(hooks->data, hooks->mlx_data, 0, 0);
	return (0);
}

void	mlx_game(t_solong *data)
{
	t_mlx	mlx_data;
	t_hooks	hooks;

	
	hooks.data = data;
	hooks.mlx_data = &mlx_data;
	mlx_data.mlx = mlx_init();
	mlx_data.assets = malloc(sizeof(void *) * 5);
	initialize_assets(&mlx_data);
	mlx_data.win = mlx_new_window(mlx_data.mlx, 32 * data->width, 32
			* (data->height + 1), "So_long");
	mlx_data.img = mlx_new_image(mlx_data.mlx, 32 * data->width, 32
			* (data->height + 1));
	initialize_wind(data, &mlx_data, 0, 0);
	sleep(1);
	mlx_hook(mlx_data.win, 17, 0, close_wind, &hooks);
	if (mlx_key_hook(mlx_data.win, movement_key, &hooks) == 0)
	{
		free_all_data_struct(data);
		print_error_or_success(Failure_game, data);
		close_wind(&hooks);
	}
	mlx_loop(mlx_data.mlx);
}

// void	ft_end_game(t_hooks *hooks)
// {
// 	mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->img);
// }