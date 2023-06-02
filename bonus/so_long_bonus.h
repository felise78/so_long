/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:46:07 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 21:29:00 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define PIX 48

# include <unistd.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
//# include "SDLmixer/SDL3/SDL.h"

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		offset;
	int		pixel;
}			t_img;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	canvas;
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
	t_pos	g;
	t_img	floor;
	t_img	wall;
	t_img	coll;
	t_img	bat[6];
	t_img	exit;
	t_img	ghost_l;
	t_img	ghost_r;
	int		score_fd;
	int		old_score;
	int		new_score;
	char	*high_score;
	char	*new_score_str;
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
void	ft_movcounts(t_data *game);
int		ft_close_window(t_data *game);
char	*gnl_fd(int fd);
int		ft_atoi(const char *s);
char	*ft_itoa(int n);
void	ft_new_score(t_data *game);
char	*ft_strcat(char *s1, char *s2);
int		ft_text(t_data *game);
int		ft_load_bat_sprite(t_data *game);
int		ft_draw_bat(t_data *game);
void	ft_highest_score(t_data *game);
void	ft_create_window(t_data *game);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_load_ghost(t_data *game);
int		ft_loop_hook(t_data *game);
void	ft_redraw(t_data *game);
void	ft_find_p(char **map, int x_max, t_pos *p);
void	ft_find_g(t_data *game);
void	ft_find_e(t_data *game);
void	ft_draw_1st_image(t_data *game);
void	ft_draw_tile(t_img *canvas, int canvas_x, int canvas_y, t_img *img);
void	ft_put_pixel(t_img *canvas, int x, int y, t_img *img);
void	ft_get_pixel(t_img *img, int x, int y);
void	ft_update_canvas(t_data *game);
void	ft_ghost_mov(t_data	*game);
void	ft_contact(t_data *game);
int		ft_init_canvas(t_data *game);
int		check_ennemy(char *s);

#endif
