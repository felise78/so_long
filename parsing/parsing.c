/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:18:16 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/16 12:06:45 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		if (game.map[y][0] == '\n')
		{
			ft_putstr("Error\nThere is an empty line inside the map\n");
			return (0);
		}
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

int check_empty_line(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i + 1])
	{
		if (s[i] == '\n' &&  s[i + 1] == '\n')
		{
			ft_putstr("Error\nThere is an empty line inside the map\n");
			return (0);
		}
		i++;
	}
	return (1);
}