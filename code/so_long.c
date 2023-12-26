/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:43:49 by nbordoni          #+#    #+#             */
/*   Updated: 2023/02/12 15:43:51 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	print_error(int fd)
{
	printf("\033[1;31m🛑ERROR: Empty map, prova qualcos'altro\n\033[0m");
	close(fd);
	exit(1);
}

void	*ft_new_window(t_program *p, int widht, int height, char *name)
{
	void	*win;

	win = mlx_new_window(p->mlx, widht, height, name);
	p->win_size.x = widht;
	p->win_size.y = height;
	return (win);
}

int	ft_close_game(t_game *g)
{
	ft_free_mat(g->map.mat);
	ft_free_sprites(g);
	mlx_destroy_window(g->game.mlx, g->game.win);
	mlx_destroy_display(g->game.mlx);
	free(g->game.mlx);
	exit(0);
}

void	lessgo(t_game *g)
{
	g->game.mlx = mlx_init();
	ft_load_sprites(g);
	g->moves = 0;
	g->c_cur = 0;
	g->game.win = ft_new_window(&g->game,
			g->map.size.x * g->sprites.size.x,
			g->map.size.y * g->sprites.size.y + 0, "./so_long");
	mlx_hook(g->game.win, 2, 1L << 0, ft_core_keys, g);
	mlx_hook(g->game.win, 17, 0, ft_close_game, g);
	mlx_loop_hook(g->game.mlx, ft_display_mat, g);
	mlx_loop(g->game.mlx);
}

int	main(int ac, char **av)
{
	t_game	var;

	(void)av;
	if (ac <= 1)
	{
		printf("\033[1;31m🛑ERROR: No argument!\n\033[0m");
		exit(1);
	}
	check_ber(av[1], ".ber");
	check_core(av[1], &var);
	lessgo(&var);
	return (0);
}
