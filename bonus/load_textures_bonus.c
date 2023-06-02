/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:34:10 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/13 14:21:22 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_load_data(t_data *game);

int	ft_load_ghost(t_data *game)
{
	int	size;

	game->ghost_l.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/ghostL_bonus.xpm", &size, &size);
	game->ghost_l.addr = mlx_get_data_addr(game->ghost_l.ptr,
			&game->ghost_l.bits_per_pixel, &game->ghost_l.size_line,
			&game->ghost_l.endian);
	game->ghost_r.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/ghostR_bonus.xpm", &size, &size);
	game->ghost_r.addr = mlx_get_data_addr(game->ghost_r.ptr,
			&game->ghost_r.bits_per_pixel, &game->ghost_r.size_line,
			&game->ghost_r.endian);
	if (game->ghost_l.ptr == NULL || game->ghost_r.ptr == NULL
		|| game->ghost_l.addr == NULL || game->ghost_r.addr == NULL)
		return (0);
	else
		return (1);
}

int	ft_load_data_bat(t_data *game)
{
	game->bat[0].addr = mlx_get_data_addr(game->bat[0].ptr,
			&game->bat[0].bits_per_pixel, &game->bat[0].size_line,
			&game->bat[0].endian);
	game->bat[1].addr = mlx_get_data_addr(game->bat[1].ptr,
			&game->bat[1].bits_per_pixel, &game->bat[1].size_line,
			&game->bat[1].endian);
	game->bat[2].addr = mlx_get_data_addr(game->bat[2].ptr,
			&game->bat[2].bits_per_pixel, &game->bat[2].size_line,
			&game->bat[2].endian);
	game->bat[3].addr = mlx_get_data_addr(game->bat[3].ptr,
			&game->bat[3].bits_per_pixel, &game->bat[3].size_line,
			&game->bat[3].endian);
	game->bat[4].addr = mlx_get_data_addr(game->bat[4].ptr,
			&game->bat[4].bits_per_pixel, &game->bat[4].size_line,
			&game->bat[4].endian);
	game->bat[5].addr = mlx_get_data_addr(game->bat[5].ptr,
			&game->bat[5].bits_per_pixel, &game->bat[5].size_line,
			&game->bat[5].endian);
	if (game->bat[0].addr == NULL || game->bat[1].addr == NULL
		|| game->bat[2].addr == NULL || game->bat[3].addr == NULL
		|| game->bat[4].addr == NULL || game->bat[5].addr == NULL)
		return (0);
	else
		return (1);
}

int	ft_load_bat_sprite(t_data *game)
{
	int	size;

	game->bat[0].ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/bat1_bonus.xpm", &size, &size);
	game->bat[1].ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/bat2_bonus.xpm", &size, &size);
	game->bat[2].ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/bat3_bonus.xpm", &size, &size);
	game->bat[3].ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/bat4_bonus.xpm", &size, &size);
	game->bat[4].ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/bat5_bonus.xpm", &size, &size);
	game->bat[5].ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/bat6_bonus.xpm", &size, &size);
	if (game->bat[0].ptr == NULL || game->bat[1].ptr == NULL || game->bat[2].ptr
		== NULL || game->bat[3].ptr == NULL || game->bat[4].ptr == NULL
		|| game->bat[5].ptr == NULL || ft_load_data_bat(game) == 0)
		return (0);
	else
		return (1);
}

int	ft_load_textures(t_data *game)
{
	int	size;

	game->floor.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/floor_bonus.xpm", &size, &size);
	game->wall.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/wall_bonus.xpm", &size, &size);
	game->coll.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/coll_bonus.xpm", &size, &size);
	game->exit.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/exit_bonus.xpm", &size, &size);
	if (game->floor.ptr == NULL || game->wall.ptr == NULL
		|| game->coll.ptr == NULL || game->exit.ptr == NULL
		|| ft_load_data(game) == 0)
		return (0);
	else
		return (1);
}

int	ft_load_data(t_data *game)
{
	game->floor.addr = mlx_get_data_addr(game->floor.ptr,
			&game->floor.bits_per_pixel, &game->floor.size_line,
			&game->floor.endian);
	game->wall.addr = mlx_get_data_addr(game->wall.ptr,
			&game->wall.bits_per_pixel, &game->wall.size_line,
			&game->wall.endian);
	game->coll.addr = mlx_get_data_addr(game->coll.ptr,
			&game->coll.bits_per_pixel, &game->coll.size_line,
			&game->coll.endian);
	game->exit.addr = mlx_get_data_addr(game->exit.ptr,
			&game->exit.bits_per_pixel, &game->exit.size_line,
			&game->exit.endian);
	if (game->floor.addr == NULL || game->wall.addr == NULL
		|| game->coll.addr == NULL || game->exit.addr == NULL)
		return (0);
	else
		return (1);
}
