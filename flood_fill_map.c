/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 05:01:00 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 05:32:09 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int flood_fill_map(t_solong *data, int x, int y)
{
    if (data->flood_fill_map[x][y] == '1' || data->flood_fill_map[x][y] == 'V')
        return (Failure_map);
    if (data->flood_fill_map[x][y] == 'C')
        data->nbr_collectibles--;
    if (data->flood_fill_map[x][y] == 'E')
        data->nbr_exit--;
    if ((data->flood_fill_map[x][y] == 'E' || data->nbr_exit == 0) && data->nbr_collectibles == 0)
        return (Success);
    data->flood_fill_map[x][y] = 'V';
    if (flood_fill_map(data, x - 1, y) == Success)
        return (Success);
    if (flood_fill_map(data, x + 1, y) == Success)
        return (Success);
    if (flood_fill_map(data, x, y - 1) == Success)
        return (Success);
    if (flood_fill_map(data, x, y + 1) == Success)
        return (Success);
    return (Failure_map);
}

int	check_flood_fill_map(t_solong *data)
{
	int x;
	int y;

	x = data->player[0];
	y = data->player[1];
	if (x < 0 || x >= data->len_i || y < 0 || y >= data->len_j)
		return (Failure_map);
    if (flood_fill_map(data, x, y) != Success)
        return (Failure_map);
}
