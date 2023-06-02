/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:48:40 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 19:48:41 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw_ghost(t_data *game, t_img *img, int mov_y)
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
			if (img->pixel != -16777216)
				ft_put_pixel(&game->canvas, x + game->g.x * PIX,
					(game->g.y * PIX + mov_y + y), img);
			x++;
		}
		y++;
	}
}

void	ft_ghost_mov(t_data	*game)
{
	static int	y;
	static int	reverse_mov = 0;

	if (game->p.x <= game->g.x)
		ft_draw_ghost(game, &game->ghost_l, y);
	else if (game->p.x > game->g.x)
		ft_draw_ghost(game, &game->ghost_r, y);
	if (reverse_mov == 1)
		y -= 8;
	else if (reverse_mov == 0 && game->g.y != (game->y_max - 2))
		y += 8;
	if (game->g.y == game->y_max - 2)
		reverse_mov = 1;
	else if (game->g.y == 1 && y == 0)
		reverse_mov = 0;
	if (y > 0 && y % PIX == 0 && reverse_mov == 0)
	{
		game->g.y++;
		y = 0;
	}
	else if (y % PIX == 0 && reverse_mov == 1)
	{
		game->g.y--;
		y = 48;
	}
}

void	ft_contact(t_data *game)
{
	if (game->p.x == game->g.x && game->p.y == game->g.y)
	{
		ft_putstr("GAME OVER\n");
		ft_close_window(game);
	}
}
