/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:08:16 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 11:08:51 by acocoual         ###   ########.fr       */
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

void movement(t_hooks *hooks, char map, int x, int y)
{
    if (map == '0')
    {
        hooks->data->tab_map[x][y] = '0';
        map = 'P';
        if (hooks->data->exit[0] == x && hooks->data->exit[1] == y)
            hooks->data->tab_map[x][y] = 'E';
    }
    if (map == 'C')
    {
        hooks->data->tab_map[x][y] = '0';
        map = 'P';
        if (hooks->data->exit[0] == x && hooks->data->exit[1] == y)
            hooks->data->tab_map[x][y] = 'E';
    }
    if (map == 'E' && hooks->data->nbr_collectibles == 0)
    {
        close_wind(hooks);
        print_error_or_success(You_win);
    }
}
