/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 02:38:53 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 06:50:42 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*create_map_in_line(int fd)
{
	char	*tmp;
	char	*line;
	char	*map_in_line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
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
	data->ber_file = strdup(argv[1]);
	if (!data->ber_file)
		return (Failure_malloc);
	data->tab_map = NULL;
	data->flood_fill_map = NULL;
	data->nbr_collectibles = 0;
	data->nbr_exit = 0;
	data->nbr_player = 0;
	data->height = 0;
	data->width = 0;
	data->exit = malloc(sizeof(int) * 2);
	if (!data->exit)
		return (free_all_data_struct(data), Failure_malloc);
	data->exit[0] = 0;
	data->exit[1] = 0;
    data->player = malloc(sizeof(int) * 2);
	if (!data->player)
		return (free_all_data_struct(data), Failure_malloc);
	data->player[0] = 0;
	data->player[1] = 0;
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
	check_and_fill_nbr(data);
	if ((data->nbr_collectibles < 1) || (data->nbr_exit != 1)
		|| (data->nbr_player != 1))
		return (free_all_data_struct(data), Failure_map);
	return (Success);
}

int parsing_so_long(t_solong *data, char **argv)
{
	int			status;

	status = Success;
	status = fill_data_struct(data, argv);
	if (status != Success)
		return (print_error_or_success(status), status);
	if (check_caracters_of_map(data) != Success)
		return (free_all_data_struct(data),
			print_error_or_success(Failure_map), Failure_map);
	if (check_square_and_borders_of_map(data) != Success)
		return (free_all_data_struct(data),
			print_error_or_success(Failure_map), Failure_map);
	status = check_flood_fill_map(data);
	if (status != Success)
		return (free_all_data_struct(data), print_error_or_success(status),
			status);
	return (Success);
}