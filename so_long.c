/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:46:22 by acocoual          #+#    #+#             */
/*   Updated: 2025/12/04 05:24:22 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_solong	data;
	int			status;

	status = Success;
	if (argc != 2)
		return (print_error_or_success(Failure_nbr_arg), EXIT_FAILURE);
	status = fill_data_struct(&data, argv);
	if (status != Success)
		return (print_error_or_success(status), EXIT_FAILURE);
	if (check_caracters_of_map(&data) != Success)
		return (free_all_data_struct(&data),
			print_error_or_success(Failure_map), Failure_map);
	status = check_flood_fill_map(&data);
	if (status != Success)
		return (free_all_data_struct(&data), print_error_or_success(status),
			status);
	return (Success);
}
