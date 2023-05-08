/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:43:55 by nbordoni          #+#    #+#             */
/*   Updated: 2023/02/12 15:43:58 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct s_mat
{
	char		**mat;
	t_vector	size;
}		t_mat;

typedef struct s_sprites
{
	void		*wall;
	void		*floor;
	void		*coll;
	void		*exit1;
	void		*hero1;
	void		*enemy1;
	t_vector	size;
}		t_sprites;

typedef struct s_program
{
	void		*mlx;
	void		*win;
	t_vector	win_size;
}		t_program;

typedef struct s_game
{
	t_program	game;
	t_mat		map;
	t_sprites	sprites;
	t_vector	sprite_pos;
	t_vector	hero_pos;
	int			c_max;
	int			c_cur;
	int			moves;
}		t_game;

int		ft_core_keys(int tasto, t_game *g);
int		ft_close_game(t_game *g);
char	**get_map(char *mapy);
void	check_core(char *path, t_game *p);
int		ft_display_mat(t_game *p);
int		ft_display_stats(t_game *g, int color);
int		ft_free_mat(char **mat);
int		ft_path_check(t_game *g, t_mat *var);
int		ft_flood_fill(char **tab, t_vector size, t_vector begin);
int		ft_load_sprites(t_game *g);
int		ft_free_sprites(t_game *g);
int		ft_print_sprite(t_game *g, void *sprite, t_vector coor);
void	check_ber(char *path, char *str);
char	*ft_free_join(char *str1, char *str2);
void	print_error(int fd);
void	*ft_new_window(t_program *p, int widht, int height, char *name);

#endif
