/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:06:23 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 18:37:13 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_pixel(t_img *img, int x, int y)
{
	img->offset = (x * (img->bits_per_pixel / 8)) + (y * img->size_line);
	img->pixel = *(unsigned int *)(img->addr + img->offset);
}

void	ft_put_pixel(t_img *canvas, int x, int y, t_img *img)
{
	canvas->offset = (x * (canvas->bits_per_pixel / 8))
		+ (y * canvas->size_line);
	*(unsigned int *)(canvas->addr + canvas->offset) = img->pixel;
}

void	ft_draw_tile(t_img *canvas, int canvas_x, int canvas_y, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < PIX)
	{
		x = 0;
		while (x < PIX)
		{
			ft_get_pixel(img, x, y);
			ft_put_pixel(canvas, x + canvas_x * PIX, y + canvas_y * PIX, img);
			x++;
		}
		y++;
	}
}

void	ft_draw_1st_image(t_data *game)
{
	game->y = 0;
	while (game->y < game->y_max)
	{
		game->x = 0;
		while (game->x < game->x_max)
		{
			if (game->map[game->y][game->x] == '0' ||
				game->map[game->y][game->x] == 'G')
				ft_draw_tile(&game->canvas, game->x, game->y, &game->floor);
			else if (game->map[game->y][game->x] == '1')
				ft_draw_tile(&game->canvas, game->x, game->y, &game->wall);
			else if (game->map[game->y][game->x] == 'C')
				ft_draw_tile(&game->canvas, game->x, game->y, &game->coll);
			else if (game->map[game->y][game->x] == 'E')
				ft_draw_tile(&game->canvas, game->x, game->y, &game->exit);
			game->x++;
		}
		game->y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->canvas.ptr, 0, 0);
}

int	ft_text(t_data *game)
{
	game->new_score_str = ft_itoa(game->new_score);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 32,
		(((game->y - 1) * PIX) + (PIX / 2)), 0xffffff, game->high_score);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		((game->x - 4) * PIX), (PIX / 2), 0xffffff, "YOUR SCORE : ");
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		((game->x - 1) * PIX), (PIX / 2), 0xffffff, game->new_score_str);
	free(game->new_score_str);
	return (0);
}

// the fonction mlx_xpm_file_to_image needs an int pointer to work, it 
// wants to save the size of the image, so we need to reserve it a 
// block of memory. 