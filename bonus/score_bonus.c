/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:50:44 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 21:40:11 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_highest_score(t_data *game)
{
	char	*str;
	char	*phrase;

	phrase = "BEST SCORE IS : ";
	game->score_fd = open("./bonus/score.txt", O_RDONLY);
	if (game->score_fd < 0)
		return ;
	else
		str = gnl_fd(game->score_fd);
	if (!str)
	{
		game->old_score = 0;
		str = ft_strdup("0");
	}
	else
		game->old_score = ft_atoi(str);
	game->high_score = ft_strcat(phrase, str);
	free(str);
	close(game->score_fd);
}

void	ft_new_score(t_data *game)
{
	char	*str;
	int		i;

	if (game->old_score == 0 || game->old_score > game->new_score)
	{
		i = 0;
		game->score_fd = open("score.txt", O_WRONLY | O_TRUNC);
		str = ft_itoa(game->new_score);
		while (str[i])
		{
			write(game->score_fd, &str[i], 1);
			i++;
		}
		free(str);
		close(game->score_fd);
	}
}

void	ft_movcounts(t_data *game)
{
	static int	i = 1;

	game->new_score = i;
	i++;
}
