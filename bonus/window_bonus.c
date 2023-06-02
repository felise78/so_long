/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:53:07 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 19:15:15 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_loop_hook(t_data *game)
{
	static int	frame;

	ft_contact(game);
	ft_draw_tile(&game->canvas, game->p.x, game->p.y, &game->floor);
	ft_draw_tile(&game->canvas, game->p.x, game->p.y, &game->bat[frame]);
	frame = (frame + 1) % 6;
	ft_draw_tile(&game->canvas, game->g.x, game->g.y, &game->floor);
	if (game->g.y < game->y_max - 2)
		ft_draw_tile(&game->canvas, game->g.x, (game->g.y + 1), &game->floor);
	ft_ghost_mov(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->canvas.ptr, 0, 0);
	ft_text(game);
	usleep(100000);
	return (0);
}

int	ft_init_canvas(t_data *game)
{
	game->canvas.ptr = mlx_new_image(game->mlx_ptr,
			(game->x_max * PIX), (game->y_max * PIX));
	if (!game->canvas.ptr)
		return (0);
	game->canvas.addr = mlx_get_data_addr(game->canvas.ptr,
			&game->canvas.bits_per_pixel, &game->canvas.size_line,
			&game->canvas.endian);
	if (!game->canvas.addr)
		return (0);
	return (1);
}

void	ft_init_game(t_data *game)
{
	game->new_score = 0;
	ft_init_canvas(game);
	ft_draw_1st_image(game);
	mlx_loop_hook(game->mlx_ptr, ft_loop_hook, game);
	game->g_exit = 0;
	mlx_hook(game->win_ptr, DestroyNotify, 0, ft_close_window, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_loop(game->mlx_ptr);
}

void	ft_create_window(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(game->x_max * PIX), (game->y_max * PIX), "BATMOON");
	if (game->win_ptr == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		return ;
	}
	if (!ft_load_textures(game) || !ft_load_bat_sprite(game)
		|| !ft_load_ghost(game))
	{
		ft_putstr("Error\nDid not find all the images\n");
		ft_close_window(game);
		return ;
	}
	ft_init_game(game);
}
