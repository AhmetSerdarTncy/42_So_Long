/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay <ahtuncay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:53:30 by ahtuncay          #+#    #+#             */
/*   Updated: 2024/01/03 16:24:07 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include <unistd.h>
#include <stdlib.h>

static void	image_control(t_data *data)
{
	if (!data->character || !data->character_left \
	|| !data->background || !data->coin || !data->wall || !data->exit)
	{
		write(2, "XPM file not found..!", 21);
		if (data->character != NULL)
			mlx_destroy_image(data->mlx_ptr, data->character);
		if (data->character_left != NULL)
			mlx_destroy_image(data->mlx_ptr, data->character_left);
		if (data->exit != NULL)
			mlx_destroy_image(data->mlx_ptr, data->exit);
		if (data->coin != NULL)
			mlx_destroy_image(data->mlx_ptr, data->coin);
		if (data->wall != NULL)
			mlx_destroy_image(data->mlx_ptr, data->wall);
		if (data->background != NULL)
			mlx_destroy_image(data->mlx_ptr, data->background);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free_map(data->map2, data->map_height);
		exit(1);
	}
}

void	load_xpm(t_data *data)
{
	int	tmp_x;
	int	tmp_y;

	data->character = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/Right.xpm", &tmp_x, &tmp_y);
	data->character_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/Left.xpm", &tmp_x, &tmp_y);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/wall.xpm", &tmp_x, &tmp_y);
	data->coin = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/Pikachu.xpm", &tmp_x, &tmp_y);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/Redoor.xpm", &tmp_x, &tmp_y);
	data->background = mlx_xpm_file_to_image(data->mlx_ptr,
			"images/sonmap.xpm", &tmp_x, &tmp_y);
	image_control(data);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map2[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->wall, x * PIXEL, y * PIXEL);
			else if (data->map2[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->coin, x * PIXEL, y * PIXEL);
			else if (data->map2[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->exit, x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->background, 0, 0);
	render_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->character, data->player_x * PIXEL, data->player_y * PIXEL);
	return (0);
}
