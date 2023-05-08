/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:42:35 by nbordoni          #+#    #+#             */
/*   Updated: 2023/02/12 15:42:37 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	ft_path_check(t_game *g, t_mat *var)
{
	int	res;
	int	check;

	g->hero_pos.y = 0;
	check = 0;
	while (g->map.mat[g->hero_pos.y] != 0 && check == 0)
	{
		g->hero_pos.x = 0;
		while (g->map.mat[g->hero_pos.y][g->hero_pos.x] != '\0' && check == 0)
		{
			if (g->map.mat[g->hero_pos.y][g->hero_pos.x] == 'P')
				check = 1;
			else
				g->hero_pos.x++;
		}
		if (!check)
			g->hero_pos.y++;
	}
	res = ft_flood_fill(var->mat, g->map.size, g->hero_pos);
	return (res);
}

int	ft_free_mat(char **mat)
{
	int	y;

	y = 0;
	while (mat[y])
	{
		free(mat[y]);
		y++;
	}
	free(mat);
	return (0);
}

void	check_ber(char *str, char *doc_ber)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	i = 0;
	count = 0;
	while (str[i])
		i++;
	if (i)
		i -= 4;
	while ((i < 0 || str[i] != '.') && str[i])
		i++;
	while (str[i])
	{
		if (str[i] == doc_ber[j])
			count++;
		j++;
		i++;
	}
	if (count == 4)
		return ;
	printf("\033[1;31m🛑ERROR:\033[1m--> Try ./so_long [MAP_NAME].ber\n\033[0m");
	exit (1);
}

int	ft_stats(t_game *g, int color)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;

	str2 = ft_itoa(g->moves);
	str = ft_strjoin("Moves: ", str2);
	mlx_string_put(g->game.mlx, g->game.win, 20, 12, color, str);
	str3 = ft_itoa(g->c_cur);
	str4 = ft_strjoin("Collectibles: ", str3);
	mlx_string_put(g->game.mlx, g->game.win, 10, 27, color, str4);
	free(str2);
	free(str);
	free(str3);
	free(str4);
	return (0);
}

int	ft_checky_enemy(t_game *g, int x, int y)
{
	if ((g->map.mat[y][x + 1] == '0' || g->map.mat[y][x + 1] == 'P'
			|| g->map.mat[y][x + 1] == 'K') && x != g->x1)
	{
		if (g->map.mat[y][x + 1] == 'P' || g->map.mat[y][x + 1] == 'K')
			return (1);
		g->map.mat[y][x] = '0';
		g->map.mat[y][x + 1] = 'F';
		x++;
		g->sprite_pos.x += g->sprites.size.x;
	}
	else if ((g->map.mat[y][x - 1] == '0'
		|| g->map.mat[y][x - 1] == 'A') && x != g->x2)
	{
		if (g->map.mat[y][x + 1] == 'A' || g->map.mat[y][x + 1] == 'K'
			|| g->map.mat[y][x + 1] == 'P')
			return (1);
		g->x1 = x - 2;
		g->map.mat[y][x] = '0';
		g->map.mat[y][x - 1] = 'F';
		x--;
		g->sprite_pos.x -= g->sprites.size.x;
	}
	return (0);
}
