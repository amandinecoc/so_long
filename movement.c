/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:08:16 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 09:51:07 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void key_high(t_solong *data)
{
    int x;
    int y;
    
    tab_player(data);
    x = data->tab_map[0];
    y = data->tab_map[1];
    movement(data, data->tab_map[x - 1][y], x, y);
    if (data->tab_map[x - 1][y] == 'E' && data->nbr_collectibles != 0)
    {
        data->exit[0] = x - 1;
        data->exit[1] = y;
        data->tab_map[x][y] = '0';
        data->tab_map[x - 1][y] ='P';
    }
}

void key_down(t_solong *data)
{
    int x;
    int y;
    
    tab_player(data);
    x = data->tab_map[0];
    y = data->tab_map[1];
    movement(data, data->tab_map[x + 1][y], x, y);
    if (data->tab_map[x + 1][y] == 'E' && data->nbr_collectibles != 0)
    {
        data->exit[0] = x + 1;
        data->exit[1] = y;
        data->tab_map[x][y] = '0';
        data->tab_map[x + 1][y] ='P';
    }
}

void key_right(t_solong *data)
{
    int x;
    int y;
    
    tab_player(data);
    x = data->tab_map[0];
    y = data->tab_map[1];
    movement(data, data->tab_map[x][y + 1], x, y);
    if (data->tab_map[x][y + 1] == 'E' && data->nbr_collectibles != 0)
    {
        data->exit[0] = x;
        data->exit[1] = y + 1;
        data->tab_map[x][y] = '0';
        data->tab_map[x][y + 1] ='P';
    }
}

void key_left(t_solong *data)
{
    int x;
    int y;
    
    tab_player(data);
    x = data->tab_map[0];
    y = data->tab_map[1];
    movement(data, data->tab_map[x][y - 1], x, y);
    if (data->tab_map[x][y - 1] == 'E' && data->nbr_collectibles != 0)
    {
        data->exit[0] = x;
        data->exit[1] = y - 1;
        data->tab_map[x][y] = '0';
        data->tab_map[x][y - 1] ='P';
    }
}

void movement(t_solong *data, char map, int x, int y)
{
    if (map == '0')
    {
        data->tab_map[x][y] = '0';
        map = 'P';
        if (data->exit[0] == x && data->exit[1] == y)
            data->tab_map[x][y] = 'E';
    }
    if (map == 'C')
    {
        data->tab_map[x][y] = '0';
        map = 'P';
        if (data->exit[0] == x && data->exit[1] == y)
            data->tab_map[x][y] = 'E';
    }
    if (map == 'E' && data->nbr_collectibles == 0)
        // end_game;
}
