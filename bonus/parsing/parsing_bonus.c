/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:18:16 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 20:49:39 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_getmap_str(t_data *game)
{
	char	*line;
	char	*all_lines;

	line = "";
	all_lines = ft_strdup("");
	line = get_next_line(*game);
	game->y_max = 0;
	while (line)
	{
		all_lines = ft_strjoin(all_lines, line);
		line = get_next_line(*game);
		game->y_max++;
	}
	return (all_lines);
}

int	check_content(char *content, t_data *game)
{
	if (check_char(content) == 1 && check_collectible(content, game) == 1
		&& check_one_exit(content) == 1 && check_one_position(content) == 1
		&& check_ennemy(content) == 1)
	{
		game->map = ft_split(content, '\n');
		game->x_max = (int)ft_strlen(game->map[0]);
		ft_find_e(game);
		ft_find_g(game);
		if (ft_map_is_rect(*game) == 1 && check_walls(*game) == 1)
		{
			if (ft_check_path(game) == 1)
			{
				free(content);
				return (1);
			}
			if (ft_check_path(game) == 0)
				ft_putstr("Error\nThe path is incorrect\n");
		}
		ft_free(game->map);
	}
	free(content);
	return (0);
}

int	ft_map_is_rect(t_data game)
{
	size_t	len;
	int		i;

	len = ft_strlen(game.map[0]);
	i = 1;
	while (game.map[i])
	{
		if (ft_strlen(game.map[i]) != len)
		{
			ft_putstr("Error\nThe map should be a rectangle\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_correct_wall_line(char *line)
{
	while (*line)
	{
		if (*line != '1')
		{
			ft_putstr("Error\nThere is a breach in the walls\n");
			return (0);
		}
		line++;
	}
	return (1);
}

int	check_walls(t_data game)
{
	int	x_max;
	int	y_max;
	int	y;

	x_max = game.x_max - 1;
	y_max = game.y_max - 1;
	y = 0;
	while (y <= y_max)
	{
		if (game.map[y][0] != '1' || game.map[y][x_max] != '1')
		{
			ft_putstr("Error\nThere is a breach in the walls\n");
			return (0);
		}
		y++;
	}
	is_correct_wall_line(game.map[0]);
	is_correct_wall_line(game.map[y_max]);
	return (1);
}
