/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 02:43:39 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 07:58:01 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_borders_of_map(t_solong *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->tab_map[0][j] != '1')
				return (Failure_map);
			else if (data->tab_map[data->height - 1][j] != '1')
				return (Failure_map);
			else if ((j == 0 || j == data->width - 1)
				&& data->tab_map[i][j] != '1')
				return (Failure_map);
			j++;
		}
		i++;
	}
	return (Success);
}

int	check_square_and_borders_of_map(t_solong *data)
{
	data->width = ft_strlen(data->tab_map[0]);
	if (data->width > 60)
		return (Failure_map);
	while (data->tab_map[data->height])
	{
		if ((int)ft_strlen(data->tab_map[data->height]) != data->width)
			return (Failure_map);
		data->height++;
	}
	if (data->height > 30)
		return (Failure_map);
	if (check_borders_of_map(data) != Success)
		return (Failure_map);
	return (Success);
}

int	check_caracters_of_map(t_solong *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->tab_map[i])
	{
		j = 0;
		while (data->tab_map[i][j])
		{
			if (data->tab_map[i][j] != '0' && data->tab_map[i][j] != '1'
				&& data->tab_map[i][j] != 'C' && data->tab_map[i][j] != 'E'
				&& data->tab_map[i][j] != 'P')
				return (Failure_map);
			j++;
		}
		i++;
	}
	return (Success);
}
