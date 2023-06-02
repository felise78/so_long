/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:06:38 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 19:50:41 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_mlx_destroy_image(void *mlx, void *img)
{
	if (img)
		mlx_destroy_image(mlx, img);
}

void	ft_close_xpm(t_data *game)
{
	ft_mlx_destroy_image(game->mlx_ptr, game->floor.ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->wall.ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->bat[0].ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->bat[1].ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->bat[2].ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->bat[3].ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->bat[4].ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->bat[5].ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->coll.ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->exit.ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->ghost_l.ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->ghost_r.ptr);
	ft_mlx_destroy_image(game->mlx_ptr, game->canvas.ptr);
}

int	ft_close_window(t_data *game)
{
	ft_close_xpm(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_free(game->map);
	free(game->high_score);
	exit(0);
}
