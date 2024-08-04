/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:31:59 by mlouati           #+#    #+#             */
/*   Updated: 2024/08/04 10:37:16 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int x, int y, int *count)
{
	if (x < 0 || y < 0 || x >= game->rows || y >= game->colons)
		return ;
	if (game->map2[x][y] == '1' || game->map2[x][y] == 'v' )
		return ;
	if (game ->map2[x][y] == 'E')
	{
		game->exit_v = 1;
		return ;
	}
	if (game->map2[x][y] == 'C')
		(*count)++;
	game->map2[x][y] = 'v';
	flood_fill(game, x - 1, y, count);
	flood_fill(game, x + 1, y, count);
	flood_fill(game, x, y + 1, count);
	flood_fill(game, x, y - 1, count);
}

void	check_chemin(t_game *game)
{
	int	count;

	count = 0;
	flood_fill(game, game->player_y, game->player_x, &count);
	if (game->collectible != count || game->exit_v == 0)
		error_msg(game, 7);
}
