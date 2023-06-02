/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:05:24 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/16 12:02:11 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	char	**map;
	int		x_max;
	int		y_max;
	int		collectible_nb;
	int		move_count;
	int		g_exit;
	int		x;
	int		y;
	t_pos	p;
	t_pos	e;
	void	*floor;
	void	*wall;
	void	*key;
	void	*bat;
	void	*exit;
}				t_data;

char	*get_next_line(t_data game);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *str, char c);
size_t	ft_strlen(const char *str);
char	*ft_line(char *line);
char	*ft_rest(char *res);
char	*ft_getmap_str(t_data *game);
void	ft_putstr(char *str);
char	*ft_strdup(char *str);
char	**ft_split(char const *s, char c);
int		check_content(char *content, t_data *game);
int		check_one_exit(char *s);
int		check_collectible(char *s, t_data *game);
int		check_char(char *s);
int		check_one_position(char *s);
int		check_walls(t_data game);
int		ft_map_is_rect(t_data game);
void	ft_free(char **split);
int		ft_check_path(t_data *game);
int		handle_keypress(int keysym, t_data *game);
int		close_window(t_data *game);
void	ft_draw_img(t_data *game);
int		ft_load_textures(t_data *game);
void	ft_print_movcounts(void);
void	ft_get_E(t_data *game);
int		ft_close_window(t_data *game);
int		check_empty_line(char *s);

#endif
