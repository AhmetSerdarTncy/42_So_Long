/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay <ahtuncay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:50:55 by ahtuncay          #+#    #+#             */
/*   Updated: 2024/01/03 12:33:21 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define PIXEL 32
# define BUFFER_SIZE 20000

# define KEY_PRESS 2
# define CLOSE_WINDOW 17

typedef struct c_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*character;
	void			*character_left;
	void			*background;
	void			*wall;
	void			*coin;
	void			*exit;
	char			**map2;
	char			*line;
	unsigned int	moves;
	int				exit_is_possible;
	int				coin_counter;
	int				x;
	int				y;
	int				player_x;
	int				player_y;
	int				map_height;
	int				map_width;
	int				ply;
	int				exitt;
}	t_data;

int		key_down(int keycode, t_data *data);
void	render_map(t_data *data);
void	free_map(char **map2, size_t height);
int		game_exit(t_data *data);
int		render(t_data *data);
int		key_down(int keycode, t_data *data);
void	start_data(char *map_name);
char	**map_constractor(t_data *data, int fd, int i);
void	ft_reset(char *buffer);
void	load_xpm(t_data *data);
int		flood_fill(t_data *data);
int		map_validation(t_data *data);
int		ft_strlen(char *str);

#endif