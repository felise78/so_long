/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:42:24 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/16 12:06:42 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_copy_map(t_data game)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = malloc(sizeof(char *) * (game.y_max + 1));
	if (!copy)
		return (NULL);
	while (i < game.y_max)
	{
		copy[i] = malloc(sizeof(char) * (game.x_max + 1));
		if (!copy[i])
			return (NULL);
		j = 0;
		while (j < game.x_max)
		{
			copy[i][j] = game.map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	ft_floodfill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	ft_floodfill(map, (x + 1), y);
	ft_floodfill(map, (x - 1), y);
	ft_floodfill(map, x, (y - 1));
	ft_floodfill(map, x, (y + 1));
}

static void	ft_find_p(char **map, int x_max, t_pos *p)
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

int	ft_check_path(t_data *game)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = ft_copy_map(*game);
	ft_find_p(map_copy, game->x_max, &game->p);
	ft_floodfill(map_copy, game->p.x, game->p.y);
	i = 1;
	while (i < game->y_max)
	{
		j = 1;
		while (j < game->x_max)
		{
			if (map_copy[i][j] == 'E' || map_copy[i][j]
				== 'C' || map_copy[i][j] == 'P')
			{
				ft_free(map_copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	ft_free(map_copy);
	return (1);
}
