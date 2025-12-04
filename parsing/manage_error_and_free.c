/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error_and_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 02:42:02 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 12:39:34 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
}
