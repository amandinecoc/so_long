/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error_and_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 02:42:02 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 15:16:26 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_exit_error(t_hooks *hooks, int status)
{
	free_all_data_struct(hooks->data);
	print_error_or_success(status, hooks->data);
	close_wind(hooks, status);
}

int	close_wind(t_hooks *hooks, int status)
{
	if (hooks->mlx_data->img != NULL)
		mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->img);
	if (hooks->mlx_data->assets[0] != NULL)
		mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[0]);
	if (hooks->mlx_data->assets[1] != NULL)
		mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[1]);
	if (hooks->mlx_data->assets[2] != NULL)
		mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[2]);
	if (hooks->mlx_data->assets[3] != NULL)
		mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[3]);
	if (hooks->mlx_data->assets[4] != NULL)
		mlx_destroy_image(hooks->mlx_data->mlx, hooks->mlx_data->assets[4]);
	if (hooks->mlx_data->win != NULL)
		mlx_destroy_window(hooks->mlx_data->mlx, hooks->mlx_data->win);
	if (hooks->mlx_data->mlx != NULL)
		mlx_destroy_display(hooks->mlx_data->mlx);
	if (hooks->mlx_data->mlx != NULL)
		free(hooks->mlx_data->mlx);
	if (hooks->mlx_data->assets != NULL)
		free(hooks->mlx_data->assets);
	exit(status);
}

void	print_mouv(t_solong *data)
{
	data->mouv++;
	ft_putstr_fd("My moves are smooth i did : ", 1);
	ft_putnbr_fd(data->mouv, 1);
	ft_putendl_fd(" steps !", 1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all_data_struct(t_solong *data)
{
	free(data->ber_file);
	if (data->tab_map != NULL)
		free_tab(data->tab_map);
	if (data->flood_fill_map != NULL)
		free_tab(data->flood_fill_map);
	if (data->exit)
		free(data->exit);
	if (data->player)
		free(data->player);
}
