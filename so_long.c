/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:46:22 by acocoual          #+#    #+#             */
/*   Updated: 2025/12/03 23:33:29 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void free_all_data_struct(t_solong *data)
{
    if (data->ber_file != NULL)
        free(data->ber_file);
    if (data->tab_map[0] != NULL)
        free_tab(data->tab_map);
    if (data->tab_map != NULL && data->tab_map[0] == NULL)
        free(data->tab_map);
    if (data->flood_fill_map[0] != NULL)
        free_tab(data->flood_fill_map);
    if (data->flood_fill_map != NULL && data->flood_fill_map[0] == NULL)
        free(data->flood_fill_map);
        
    // finir
}

int find_location_exit_in_map(t_solong *data)
{

}

int check_and_fill_nbr(t_solong *data)
{
    
}

int create_tab_map_and_flood_fill_map(t_solong *data)
{
    int fd;
    char *line;
    char *tmp;
    char *map_in_line;
    
    fd = open(data->ber_file, O_RDONLY);
    if (fd < 0)
        return (Failure_open);
    line = get_next_line(fd);
    if (!line)
        return (Failure_malloc);
    map_in_line = ft_strdup("");
    while (line != NULL)
    {
        tmp = map_in_line;
        map_in_line = ft_strjoin(tmp, line);
        if (!map_in_line)
            return (Failure_malloc);
        free(tmp);
        free(line);
        line = get_next_line(fd);
    }
    data->tab_map = ft_split(map_in_line, '\n');
    if (!data->tab_map)
        return (free(map_in_line), Failure_malloc);
    data->flood_fill_map = ft_split(map_in_line, '\n');
    if (!data->flood_fill_map)
        return(free(map_in_line), Failure_malloc);
    free(map_in_line);
    return (Success);
}

int initialize_data_struct(t_solong *data, char **argv)
{
    int status;

    data->ber_file = strdup(argv[1]);
    if (!data->ber_file)
        return (Failure_malloc);
    data->tab_map = NULL;
    data->flood_fill_map = NULL;
    data->nbr_collectibles = 0;
    data->nbr_exit = 0;
    data->nbr_player = 0;
    data->exit = malloc(sizeof(int) * 2);
    if (!data->exit)
        return (free_all_data_struct(data), status);
    data->exit[0] = 0;
    data->exit[1] = 0;
    data->mouv = 0;
    return (Success);
}

int fill_data_struct(t_solong *data, char **argv)
{
    int status;
    
    status = initialize_data_struct(data, argv);
    if (status != Success)
        return (status);
    if (ft_strnstr(data->ber_file, ".ber", ft_strlen(data->ber_file)) != NULL) //je peux juste verifier si ber_file[0] est lettre puis strnstr
    {
        if ((ft_strlen(data->ber_file) - 5) <= 'a' || (ft_strlen(data->ber_file) - 5) >= 'z')
            return (free_all_data_struct(data), Failure_map);
    }
    status = create_tab_map_and_flood_fill_map(data);
    if (status != Success)
        return (free(data->ber_file), status);
    status = check_and_fill_nbr(data);
    if (status != Success)
        return (free_all_data_struct(data), status);
    status = find_location_exit_in_map(data);
    if (status != Success)
        return (free_all_data_struct(data), status);
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
    status = fill_data_struct(&data, argv);
    if (status != Success)
        return (print_error_or_success(status), EXIT_FAILURE);
}
