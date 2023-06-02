/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:53:28 by hemottu           #+#    #+#             */
/*   Updated: 2023/04/26 11:03:13 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_data *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->key)
		mlx_destroy_image(game->mlx_ptr, game->key);
	if (game->bat)
		mlx_destroy_image(game->mlx_ptr, game->bat);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_free(game->map);
	exit(0);
}

void	ft_render_exit(t_data *game, int x, int y)
{
	if (game->collectible_nb == 0)
	{
		ft_putstr("Bravo!\n");
		ft_close_window(game);
	}
	else
	{
		game->map[game->p.y][game->p.x] = '0';
		game->map[game->p.y + y][game->p.x + x] = 'P';
		game->p.x += x;
		game->p.y += y;
		ft_print_movcounts();
		ft_draw_img(game);
		game->g_exit = 1;
	}
}

void	ft_render_movement(t_data *game, int x, int y)
{
	if (game->map[game->p.y + y][game->p.x + x] == '1')
		return ;
	else if (game->map[game->p.y + y][game->p.x + x] == 'C')
		game->collectible_nb--;
	else if (game->map[game->p.y + y][game->p.x + x] == 'E')
	{
		game->e.x = game->p.x + x;
		game->e.y = game->p.y + y;
		ft_render_exit(game, x, y);
		return ;
	}
	if (game->g_exit == 0)
		game->map[game->p.y][game->p.x] = '0';
	else
	{
		game->map[game->p.y][game->p.x] = 'E';
		game->g_exit = 0;
	}
	game->map[game->p.y + y][game->p.x + x] = 'P';
	game->p.x += x;
	game->p.y += y;
	ft_print_movcounts();
	ft_draw_img(game);
}

int	handle_keypress(int keysym, t_data *game)
{
	if (keysym == XK_Escape)
	{
		ft_close_window(game);
	}
	if (keysym == XK_a || keysym == XK_w || keysym == XK_s || keysym == XK_d)
	{
		if (keysym == XK_a)
			ft_render_movement(game, -1, 0);
		else if (keysym == XK_d)
			ft_render_movement(game, 1, 0);
		else if (keysym == XK_s)
			ft_render_movement(game, 0, 1);
		else if (keysym == XK_w)
			ft_render_movement(game, 0, -1);
	}
	return (1);
}
