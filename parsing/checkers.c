/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:45:26 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/16 12:06:44 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_content(char *content, t_data *game)
{
	if ((check_char(content) + check_collectible(content, game)
			+ check_one_exit(content) + check_one_position(content)) == 4)
	{
		game->map = ft_split(content, '\n');
		game->x_max = (int)ft_strlen(game->map[0]);
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

int	check_collectible(char *s, t_data *game)
{
	size_t	i;

	i = 0;
	game->collectible_nb = 0;
	while (s[i])
	{
		if (s[i] == 'C')
			game->collectible_nb++;
		i++;
	}
	if (game->collectible_nb == 0)
	{
		ft_putstr("Error\nThere is no collectible\n");
		return (0);
	}
	else
		return (1);
}

int	check_char(char *s)
{
	char	*charset;
	int		i;
	int		j;

	i = 0;
	j = 0;
	charset = "10CEP\n";
	while (s[i])
	{
		if (s[i] != charset[j] && j == 5)
		{
			ft_putstr("Error\n'1''0''P''C''E' chars only\n");
			return (0);
		}
		else if (s[i] != charset[j] && j < 5)
		{
			j++;
		}
		else if (s[i] == charset[j])
		{
			i++;
			j = 0;
		}
	}
	if (check_empty_line(s) == 0)
		return (0);
	return (1);
}

int	check_one_exit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'E')
		{
			i++;
			while (s[i] && s[i] != 'E')
				i++;
			if (s[i] == 'E')
			{	
				ft_putstr("Error\nThere should be 1 exit only\n");
				return (0);
			}
			else
				return (1);
		}
		i++;
	}
	ft_putstr("Error\nThere is no exit\n");
	return (0);
}

int	check_one_position(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'P')
		{
			i++;
			while (s[i] && s[i] != 'P')
				i++;
			if (s[i] == 'P')
			{	
				ft_putstr("Error\nThere should be 1 P only\n");
				return (0);
			}
			else
				return (1);
		}
		i++;
	}
	ft_putstr("Error\nThere is no start position\n");
	return (0);
}
