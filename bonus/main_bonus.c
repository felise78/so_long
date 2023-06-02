/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:36:13 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 18:42:31 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_check_file_ext(char *s)
{
	int		len;
	char	*s2;
	int		i;

	len = ft_strlen(s) - 1;
	s2 = ".ber";
	i = 3;
	while (s[len] && s2[i])
	{
		if (s[len] != s2[i])
			return (0);
		len--;
		i--;
	}
	return (1);
}

int	ft_check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Error\nYou must have 1 argument\n");
		return (0);
	}
	if (!ft_check_file_ext(av[1]))
	{
		ft_putstr("Error\nYou must have a .ber file\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	game;
	char	*str;

	if (!ft_check_arg(ac, av))
		return (1);
	game.fd = open(av[1], O_RDONLY);
	if (game.fd < 0)
	{
		ft_putstr("Error\nCouldn't open the file\n");
		return (1);
	}
	str = ft_getmap_str(&game);
	if (check_content(str, &game) == 1)
	{
		ft_highest_score(&game);
		ft_create_window(&game);
	}
	return (0);
}
