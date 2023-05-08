/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:43:22 by nbordoni          #+#    #+#             */
/*   Updated: 2023/02/12 15:43:25 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	ft_square_check(char **mat)
{
	int	check;
	int	y;

	y = 0;
	check = 0;
	while (mat[y] && check == 0)
	{
		if (ft_strlen(mat[y]) != ft_strlen(mat[0]))
			check = 1;
		y++;
	}
	return (check);
}

static int	ft_wall_check(char **mat, int xmax, int ymax)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	if (mat)
	{
		while (i < ymax && check == 0)
		{
			if (mat[i][0] != '1' || mat[i][xmax - 1] != '1')
				check = 1;
			i++;
		}
		i = 0;
		while (i < xmax && check == 0)
		{
			if (mat[0][i] != '1' || mat[ymax - 1][i] != '1')
				check = 1;
			i++;
		}
	}
	return (check);
}

static int	ft_char_check(t_game *g, int check)
{
	int	x;
	int	y;

	g->c_max = 0;
	y = 0;
	while (y < g->map.size.y)
	{
		x = 0;
		while (x < g->map.size.x)
		{
			if (g->map.mat[y][x] == 'C')
				g->c_max++;
			else if (g->map.mat[y][x] == 'P')
				check += 2;
			else if (g->map.mat[y][x] == 'E')
				check += 3;
			else if (g->map.mat[y][x] != '0' && g->map.mat[y][x] != '1')
				check += 4;
			x++;
		}
		y++;
	}
	if (check == 6 && g->c_max >= 1)
		check = 0;
	return (check);
}

static int	ft_mat_size(t_mat *t)
{
	t->size.x = 0;
	t->size.y = 0;
	while (t->mat[0][t->size.x] != '\0')
		t->size.x++;
	while (1)
	{
		if (!t->mat[t->size.y])
		{
			break ;
		}
		t->size.y++;
	}
	return (0);
}

void	check_core(char *str, t_game *var)
{
	t_mat	matr;
	int		err;

	err = 0;
	matr.mat = get_map(str);
	var->map.mat = get_map(str);
	ft_mat_size(&var->map);
	if (ft_square_check(var->map.mat) != 0)
		err = ft_printf("\033[1;31m🛑ERROR:\nmap is not rectangular.\n\033[0m");
	if (ft_wall_check(var->map.mat, var->map.size.x, var->map.size.y))
		err = ft_printf("\033[1;31m🛑ERROR:\n0 on walls.\n\033[0m");
	if (ft_char_check(var, 1))
		err = ft_printf("\033[1;31m🛑ERROR:\nInvalid elements.\n\033[0m");
	if (ft_path_check(var, &matr))
		err = ft_printf("\033[1;31m🛑ERROR:\nThe E/C is unreachable.\n\033[0m");
	ft_free_mat(matr.mat);
	if (err)
	{
		ft_free_mat(var->map.mat);
		exit(1);
	}
}
