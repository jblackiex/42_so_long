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
#include "so_long.h"

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
	exit(1);
}
