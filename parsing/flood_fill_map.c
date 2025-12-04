/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 05:01:00 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 15:08:35 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	flood_fill_map(t_solong *data, int x, int y)
{
	if (data->flood_fill_map[x][y] == '1' || data->flood_fill_map[x][y] == 'V')
		return (Failure_map);
	if (data->flood_fill_map[x][y] == 'C')
		data->nbr_collectibles--;
	if (data->flood_fill_map[x][y] == 'E')
		data->nbr_exit--;
	if ((data->flood_fill_map[x][y] == 'E' || data->nbr_exit == 0)
		&& data->nbr_collectibles == 0)
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
	int	x;
	int	y;
	int	cache_collectibles;

	cache_collectibles = data->nbr_collectibles;
	x = data->player[0];
	y = data->player[1];
	if (x <= 0 || x >= data->height || y <= 0 || y >= data->width)
		return (Failure_map);
	if (flood_fill_map(data, x, y) != Success)
		return (Failure_map);
	data->nbr_collectibles = cache_collectibles;
	return (Success);
}
