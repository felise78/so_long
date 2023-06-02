/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:40:25 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 21:28:38 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_find_p(char **map, int x_max, t_pos *p)
{
	p->x = 0;
	p->y = 0;
	while (map[p->y][p->x] && map[p->y][p->x] != 'P')
	{
		if (p->x == (x_max - 1))
		{
			p->x = 0;
			p->y++;
		}
		p->x++;
	}
}

void	ft_find_g(t_data *game)
{
	game->g.x = 0;
	game->g.y = 0;
	while (game->map[game->g.y][game->g.x]
		&& game->map[game->g.y][game->g.x] != 'G')
	{
		if (game->g.x == (game->x_max - 1))
		{
			game->g.x = 0;
			game->g.y++;
		}
		game->g.x++;
	}
}

void	ft_find_e(t_data *game)
{
	game->e.x = 0;
	game->e.y = 0;
	while (game->map[game->e.y][game->e.x]
		&& game->map[game->e.y][game->e.x] != 'E')
	{
		if (game->e.x == (game->x_max - 1))
		{
			game->e.x = 0;
			game->e.y++;
		}
		game->e.x++;
	}
}
