/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay  <ahtuncay@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:39:56 by ahtuncay          #+#    #+#             */
/*   Updated: 2023/12/30 16:00:40 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_ret(t_data *data)
{
	int		i;

	i = 1;
	data->map_width = ft_strlen(data->map2[0]);
	while (i < data->map_height)
	{
		if (data->map_width != ft_strlen(data->map2[i]))
			return (1);
		if (data->map_height == ft_strlen(data->map2[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	is_wall(char **map2, int x, int y)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	while (j < x)
	{
		if (map2[0][j] != '1' || map2[y - 1][j] != '1')
			return (1);
		j++;
	}
	i = 1;
	len = ft_strlen(map2[i]);
	while (i < y - 1)
	{
		if (map2[i][0] != '1' || map2[i][len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	is_pec(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map2[i][j] == 'P')
				data->ply++;
			else if (data->map2[i][j] == 'E')
				data->exitt++;
			else if (data->map2[i][j] == 'C')
				data->coin_counter++;
			j++;
		}
		i++;
	}
	if (data->ply != 1 || data->exitt != 1 || data->coin_counter == 0)
		return (1);
	return (0);
}

static int	is_chr(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map2[i][j] != 'P' && data->map2[i][j] != 'E'
				&& data->map2[i][j] != 'C'
				&& data->map2[i][j] != '0' && data->map2[i][j] != '1')
				return (1);
			if (data->map2[i][j] == 'P')
			{
				data->player_y = i;
				data->player_x = j;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	map_validation(t_data *data)
{
	if (is_ret(data))
		return (1);
	if (is_pec(data))
		return (1);
	if (is_chr(data))
		return (1);
	if (is_wall(data->map2, data->map_width, data->map_height))
		return (1);
	if (flood_fill(data))
		return (1);
	return (0);
}
