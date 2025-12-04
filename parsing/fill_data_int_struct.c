/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_int_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 06:46:09 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 06:50:07 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void fill_tab_int(int *tab, int i, int j)
{
    tab[0] = i;
    tab[1] = j;
}

void	check_and_fill_nbr(t_solong *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->tab_map[i])
	{
		j = 0;
		while (data->tab_map[j])
		{
			if (data->tab_map[i][j] == 'C')
				data->nbr_collectibles++;
			else if (data->tab_map[i][j] == 'E')
			{
				data->nbr_exit++;
				fill_tab_int(data->exit, i, j);
			}
			else if (data->tab_map[i][j] == 'P')
            {
				data->nbr_player++;
                fill_tab_int(data->player, i, j);
            }
			j++;
		}
		i++;
	}
    printf("exitx = %d exity = %d\nplayerx = %d playery = %d\n", data->exit[0], data->exit[1], data->player[0], data->player[1]);
}
