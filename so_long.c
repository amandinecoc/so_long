/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:46:22 by acocoual          #+#    #+#             */
/*   Updated: 2025/12/04 15:16:07 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error_or_success(int status, t_solong *data)
{
	if (status == You_win)
	{
		ft_putstr_fd("You Won in : ", 1);
		ft_putnbr_fd(data->mouv, 1);
		ft_putendl_fd(" steps !", 1);
	}
	if (status == Failure_nbr_arg)
		ft_putendl_fd("ERROR : Invalid number of arguments", 2);
	if (status == Failure_map)
		ft_putendl_fd("ERROR : Invalid map", 2);
	if (status == Failure_malloc)
		ft_putendl_fd("ERROR : memory allocation", 2);
	if (status == Failure_open)
		ft_putendl_fd("ERROR : file descriptor", 2);
	if (status == Failure_game)
		ft_putendl_fd("ERROR : game", 2);
	if (status == game_escape)
		ft_putendl_fd("You escaped the Game !", 1);
	if (status == error_asset)
		ft_putendl_fd("ERROR : asset is incorrect", 2);
}

void	tab_player(t_solong *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->tab_map[i])
	{
		j = 0;
		while (data->tab_map[i][j])
		{
			if (data->tab_map[i][j] == 'P')
			{
				data->player[0] = i;
				data->player[1] = j;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_solong	data;
	int			status;

	status = Success;
	if (argc != 2)
		return (print_error_or_success(Failure_nbr_arg, &data), EXIT_FAILURE);
	status = parsing_so_long(&data, argv);
	if (status != Success)
		return (status);
	mlx_game(&data);
	return (free_all_data_struct(&data), Success);
}
