/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:45:26 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 20:26:24 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	charset = "10GCEP\n";
	while (s[i])
	{
		if (s[i] != charset[j] && j == 6)
		{
			ft_putstr("Error\n'1''0''P''C''E''G' chars only\n");
			return (0);
		}
		else if (s[i] != charset[j] && j < 6)
		{
			j++;
		}
		else if (s[i] == charset[j])
		{
			i++;
			j = 0;
		}
	}
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

int	check_ennemy(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'G')
		{
			i++;
			while (s[i] && s[i] != 'G')
				i++;
			if (s[i] == 'G')
			{	
				ft_putstr("Error\nThere should be 1 ennemy\n");
				return (0);
			}
			else
				return (1);
		}
		i++;
	}
	ft_putstr("Error\nThere is no ennemy\n");
	return (0);
}
