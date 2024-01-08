/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay <ahtuncay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:04:23 by ahtuncay          #+#    #+#             */
/*   Updated: 2024/01/03 16:12:11 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void	filename_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
	{
		return ;
	}
	write(2, "ERROR_MAP_NAME\n", 15);
	exit (1);
}

static void	game_init(t_data *data)
{
	data->coin_counter = 0;
	data->exitt = 0;
	data->ply = 0;
	data->moves = 0;
}

static	void	game_run(t_data *data)
{
	mlx_hook(data->win_ptr, KEY_PRESS, 0, key_down, data);
	mlx_hook(data->win_ptr, CLOSE_WINDOW, 0, game_exit, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_loop (data->mlx_ptr);
}

static	void	error(t_data *data)
{
	write(2, "ERROR\n", 6);
	free_map(data->map2, data->map_height);
	exit(1);
}

void	start_data(char *map_name)
{
	t_data	data;
	int		fd;
	int		i;

	i = -1;
	filename_check(map_name);
	game_init(&data);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (write(2, "Wrong_file_path\n", 16), exit(1));
	data.map2 = map_constractor(&data, fd, i);
	close(fd);
	if (!data.map2)
		exit(0);
	if (map_validation(&data))
		return (error(&data));
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (error(&data));
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			data.map_width * PIXEL, data.map_height * PIXEL, "so_long");
	if (!data.win_ptr)
		return (error(&data));
	load_xpm(&data);
	game_run(&data);
}
