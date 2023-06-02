/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:55:58 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 20:36:22 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_textures(t_data *game)
{
	int	size;

	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/floor.xpm", &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/wall.xpm", &size, &size);
	game->key = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/key.xpm", &size, &size);
	game->bat = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/bat.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/ladder.xpm", &size, &size);
	if (game->floor == NULL || game->wall == NULL || game->key
		== NULL || game->bat == NULL || game->exit == NULL)
		return (0);
	else
		return (1);
}

void	ft_draw_img(t_data *game)
{
	game->y = 0;
	while (game->y < game->y_max)
	{
		game->x = 0;
		while (game->x < game->x_max)
		{
			if (game->map[game->y][game->x] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->floor, (32 * game->x), (32 * game->y));
			else if (game->map[game->y][game->x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->wall, (32 * game->x), (32 * game->y));
			else if (game->map[game->y][game->x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->key, (32 * game->x), (32 * game->y));
			else if (game->map[game->y][game->x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->bat, (32 * game->x), (32 * game->y));
			else if (game->map[game->y][game->x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->exit, (32 * game->x), (32 * game->y));
			game->x++;
		}
		game->y++;
	}
}

// the fonction mlx_xpm_file_to_image needs an int pointer to work, it 
// wants to save the size of the image, so we need to reserve it a 
// block of memory. 

// I had leaks because I was loading the textures everytime I draw an image.
// I just need to load it once before the first image.