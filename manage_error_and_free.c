/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error_and_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 02:42:02 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 02:42:36 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	free(data->exit);
}

void	print_error_or_success(int status)
{
	if (status == You_win)
		ft_putendl_fd("You win !", 1);
	if (status == Failure_nbr_arg)
		ft_putendl_fd("ERROR : Invalid number of arguments", 2);
	if (status == Failure_map)
		ft_putendl_fd("ERROR : Invalid map", 2);
	if (status == Failure_malloc)
		ft_putendl_fd("ERROR : memory allocation", 2);
}