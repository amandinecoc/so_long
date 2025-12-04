/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 02:38:53 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 02:56:00 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_and_fill_nbr(t_solong *data)
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
				data->exit[0] = i;
				data->exit[1] = j;
			}
			else if (data->tab_map[i][j] == 'P')
            {
				data->nbr_player++;
                data->player[0] = i;
                data->player[1] = j;
            }
			j++;
		}
		i++;
	}
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
    data->player = malloc(sizeof(int) * 2);
	if (!data->player)
		return (free_all_data_struct(data), status);
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
	check_and_fill_nbr(data);
	if ((data->nbr_collectibles < 1) || (data->nbr_exit != 1)
		|| (data->nbr_player != 1))
		return (free_all_data_struct(data), Failure_map);
	return (Success);
}
