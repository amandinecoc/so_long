/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:46:22 by acocoual          #+#    #+#             */
/*   Updated: 2025/12/03 19:27:15 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int free_all_data_struct(t_solong *data)
{
    
}

int find_location_exit_in_map(t_solong *data)
{

}

int check_and_fill_nbr(t_solong *data)
{
    
}

int create_tab_map(t_solong *data)
{
    
}

int initialize_data_struct(t_solong *data, char **argv)
{
    int status;

    data->str_map = strdup(argv[1]);
    data->tab_map = NULL;
    data->flood_fill_map = NULL;
    status = create_tab_map(data);
    if (status != Success)
        return (free(data->str_map), status);
    data->nbr_collectibles = 0;
    data->nbr_exit = 0;
    data->nbr_player = 0;
    status = check_and_fill_nbr(data);
    if (status != Success)
        return (free_all_data_struct(data), status);
    data->exit = malloc(sizeof(int) * 2);
    if (!data->exit)
        return (free_all_data_struct(data), status);
    data->exit[0] = 0;
    data->exit[1] = 0;
    status = find_location_exit_in_map(data);
    if (status != Success)
        return (free_all_data_struct(data), status);
    data->mouv = 0;
    return (Success);
}

void print_error_or_success(int status)
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

int main(int argc, char **argv)
{
    t_solong data;
    int status;
    
    status = Success;
    if (argc != 2)
        return (print_error_or_success(Failure_nbr_arg), EXIT_FAILURE);
    status = initialize_data_struct(&data, argv);
    if (status != Success)
        return (print_error_or_success(status), EXIT_FAILURE);
}
