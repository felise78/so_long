/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:36:13 by hemottu           #+#    #+#             */
/*   Updated: 2023/04/26 13:32:06 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_create_window(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(game->x_max * 32), (game->y_max * 32), "BATMOON");
	if (game->win_ptr == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		return ;
	}
	if (!ft_load_textures(game))
	{
		ft_putstr("Error\nDid not find all the images\n");
		ft_close_window(game);
		return ;
	}
	ft_draw_img(game);
	game->g_exit = 0;
	mlx_hook(game->win_ptr, DestroyNotify, 0, ft_close_window, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_loop(game->mlx_ptr);
}

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

int	main(int ac, char **av)
{
	t_data	game;
	char	*str;

	if (ac != 2)
	{
		ft_putstr("Error\nYou must have 1 argument\n");
		return (1);
	}
	if (!ft_check_file_ext(av[1]))
	{
		ft_putstr("Error\nYou must have a .ber file\n");
		return (1);
	}
	game.fd = open(av[1], O_RDONLY);
	if (game.fd < 0)
	{
		ft_putstr("Error\nCouldn't open the file\n");
		return (1);
	}
	str = ft_getmap_str(&game);
	if (check_content(str, &game) == 1)
		ft_create_window(&game);
	return (0);
}
