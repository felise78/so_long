/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:53:28 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 19:08:43 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exit(t_data *game, int x, int y)
{
	if (game->collectible_nb == 0)
	{
		ft_movcounts(game);
		ft_new_score(game);
		ft_putstr("GG, you finished the game!\n");
		ft_close_window(game);
	}
	else
	{
		ft_draw_tile(&game->canvas, game->p.x, game->p.y, &game->floor);
		game->p.x += x;
		game->p.y += y;
		ft_movcounts(game);
		game->g_exit = 1;
	}
}

void	ft_movement(t_data *game, int x, int y)
{
	if (game->map[game->p.y + y][game->p.x + x] == '1')
		return ;
	else if (game->map[game->p.y + y][game->p.x + x] == 'C')
	{
		game->collectible_nb--;
		game->map[game->p.y + y][game->p.x + x] = '0';
	}
	else if (game->map[game->p.y + y][game->p.x + x] == 'E')
	{
		ft_exit(game, x, y);
		return ;
	}
	if (game->g_exit == 0)
		ft_draw_tile(&game->canvas, game->p.x, game->p.y, &game->floor);
	else
	{
		ft_draw_tile(&game->canvas, game->p.x, game->p.y, &game->exit);
		game->g_exit = 0;
	}
	game->p.x += x;
	game->p.y += y;
	ft_movcounts(game);
}

int	handle_keypress(int keysym, t_data *game)
{
	if (keysym == XK_Escape || keysym == 53)
	{
		ft_close_window(game);
	}
	if (keysym == XK_a || keysym == XK_w || keysym == XK_s || keysym == XK_d)
	{
		if (keysym == XK_a)
			ft_movement(game, -1, 0);
		else if (keysym == XK_d)
			ft_movement(game, 1, 0);
		else if (keysym == XK_s)
			ft_movement(game, 0, 1);
		else if (keysym == XK_w)
			ft_movement(game, 0, -1);
	}
	return (1);
}

//g_exit lets me know if the bat was on the exit and I need to draw it again.