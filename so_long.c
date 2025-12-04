/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:46:22 by acocoual          #+#    #+#             */
/*   Updated: 2025/12/04 06:54:08 by amandine         ###   ########.fr       */
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
	status = parsing_so_long(&data, argv);
	if (status != Success)
		return (status);
	return (free_all_data_struct(&data), Success);
}
