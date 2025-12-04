/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:46:22 by acocoual          #+#    #+#             */
/*   Updated: 2025/12/04 02:36:27 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_borders_of_map(t_solong *data, int len_i, int len_j)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i <= len_i)
    {
        j = 0;
        while (j <= len_j)
        {
            if (data->tab_map[0][j] != '1')
                return (Failure_map);
            else if (data->tab_map[len_i][j] != '1')
                return (Failure_map);
            else if ((j == 0 || j == len_j) && data->tab_map[i][j] != '1')
                return (Failure_map);
            j++;
        }
        i++;
    }
    return (Success);
}

int check_square_and_borders_of_map(t_solong *data)
{
    int len_i;
    int len_j;
    
    len_i = 0;
    len_j = ft_strlen(data->tab_map[0]);
    if (len_j > 60)
        return (Failure_map);
    while (data->tab_map[len_i])
    {
        if (ft_strlen(data->tab_map[len_i]) != len_j)
            return (Failure_map);
        len_i++;
    }
    if (len_i > 30)
        return (Failure_map);
    if (check_borders_of_map(data, len_i, len_j) != Success)
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
			if (data->tab_map[i][j] != '0' || data->tab_map[i][j] != '1'
				|| data->tab_map[i][j] != 'C' || data->tab_map[i][j] != 'E'
				|| data->tab_map[i][j] != 'P')
                return (Failure_map);
            i++;
		}
        i++;
	}
    return (Success);
}

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

void	place_exit(t_solong *data, int i, int j)
{
	data->exit[0] = i;
	data->exit[1] = j;
}

int	check_and_fill_nbr(t_solong *data)
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
				place_exit(data, i, j);
			}
			else if (data->tab_map[i][j] == 'P')
				data->nbr_player++;
			j++;
		}
		i++;
	}
	if ((data->nbr_collectibles < 1) || (data->nbr_exit != 1)
		|| (data->nbr_player != 1))
		return (Failure_map);
	return (Success);
}

char	*create_map_in_line(int fd)
{
	char	*tmp;
	char	*line;
	char	*map_in_line;

	line = get_next_line(fd);
	if (!line)
		return (Failure_malloc);
	map_in_line = ft_strdup("");
	if (!map_in_line)
		return (NULL);
	while (line != NULL)
	{
		tmp = map_in_line;
		map_in_line = ft_strjoin(tmp, line);
		if (!map_in_line)
			return (free(tmp), free(line), NULL);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	return (map_in_line);
}

int	create_tab_map_and_flood_fill_map(t_solong *data)
{
	int		fd;
	char	*tmp;
	char	*map_in_line;

	fd = open(data->ber_file, O_RDONLY);
	if (fd < 0)
		return (Failure_open);
	map_in_line = create_map_in_line(fd);
	data->tab_map = ft_split(map_in_line, '\n');
	if (!data->tab_map)
		return (free(map_in_line), Failure_malloc);
	data->flood_fill_map = ft_split(map_in_line, '\n');
	if (!data->flood_fill_map)
		return (free(map_in_line), Failure_malloc);
	free(map_in_line);
	return (Success);
}

int	initialize_data_struct(t_solong *data, char **argv)
{
	int	status;

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

int	fill_data_struct(t_solong *data, char **argv)
{
	int	status;

	status = initialize_data_struct(data, argv);
	if (status != Success)
		return (status);
	if (ft_strnstr(data->ber_file, ".ber", ft_strlen(data->ber_file)) != NULL)
		// je peux juste verifier si ber_file[0] est lettre puis strnstr
	{
		if ((ft_strlen(data->ber_file) < 5)
			|| data->ber_file[ft_strlen(data->ber_file) - 5] <= 32
			|| data->ber_file[ft_strlen(data->ber_file) - 5] >= 127)
			// ne peut pas etre . ou /
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
		return (free_all_data_struct(&data), print_error_or_success(Failure_map), Failure_map);
    status = flood_fill_map(&data);
    if (status != Success)
        return (free_all_data_struct(&data), print_error_or_success(status), status);
    return (Success);
}
