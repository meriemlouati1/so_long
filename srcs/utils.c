/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:10:56 by mlouati           #+#    #+#             */
/*   Updated: 2024/08/04 10:24:29 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_elements(t_game *game, int i, int j)
{
	while (++i < game->rows)
	{
		while (++j < game->colons)
		{
			if (game->map[i][j] == 'C')
				game->collectible++;
			else if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				game ->count_p++;
			}
			else if (game->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
				game ->count_e++;
			}
			else if (game->map[i][j] != 'C' && game->map[i][j] != 'P'
					&& game->map[i][j] != 'E' && game->map[i][j] != '0'
					&& game->map[i][j] != '1')
				error_msg(game, 6);
		}
		j = -1;
	}
}

void	check_content(t_game *game)
{
	check_elements(game, -1, -1);
	if (game->collectible == 0)
	{
		free_game(game);
		write(1, "Error\n", 6);
		write(1, "the map doesn't have any collectible\n", 37);
		exit(0);
	}
	if (game ->count_e != 1)
	{
		free_game(game);
		write(1, "Error\n", 6);
		write(1, "the map has no exit or more than one\n", 37);
		exit(0);
	}
	if (game ->count_p != 1)
	{
		free_game(game);
		write(1, "Error\n", 6);
		write(1, "the map has no player or more than one\n", 39);
		exit(0);
	}
}

void	check_edge(t_game *game)
{
	int	rows;
	int	i;
	int	len;

	rows = 0;
	while (game->map[rows])
		rows++;
	i = 0;
	len = ft_strlen(game->map[0]);
	while (i < len)
	{
		if (game->map[0][i] != '1' || game->map[rows - 1][i] != '1')
			error_msg(game, 5);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
			error_msg(game, 5);
		i++;
	}
	game->rows = rows;
}

void	check_form(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len)
		{
			free_game(game);
			write(2, "Error\n", 6);
			write(1, "The map is not rectangular\n", 27);
			exit(0);
		}
		i++;
	}
	game->colons = len;
}

void	error_msg(t_game *game, int nb)
{
	free_game(game);
	write(2, "Error\n", 6);
	if (nb == 0)
		write(1, "Incorrect numbers of params\n", 28);
	if (nb == 1)
		write(1, "Invalid extension\n", 18);
	if (nb == 2)
		write(1, "Invalid fd\n", 11);
	if (nb == 3)
		write(1, "Invalid map\n", 12);
	if (nb == 4)
		write(1, "Empty line in the map\n", 22);
	if (nb == 5)
		write(1, "The borders don't contain only walls\n", 37);
	if (nb == 6)
		write(1, "The map contains invalid characters\n", 36);
	if (nb == 7)
		write(1, "Invalid path\n", 13);
	if (nb == 8)
		write(1, "The maps's width exceeds the screen\n", 36);
	if (nb == 9)
		write(1, "The map's height exceeds the screen\n", 36);
	exit(0);
}
