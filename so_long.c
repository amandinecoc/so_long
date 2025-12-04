/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:46:22 by acocoual          #+#    #+#             */
/*   Updated: 2025/12/04 09:17:08 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void tab_player(t_solong *data)
{
	int i;
	int j;

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
		return (print_error_or_success(Failure_nbr_arg), EXIT_FAILURE);
	status = parsing_so_long(&data, argv);
	if (status != Success)
		return (status);
	return (free_all_data_struct(&data), Success);
}
