/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:14:15 by mlouati           #+#    #+#             */
/*   Updated: 2024/07/31 09:49:26 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_to_image(t_game *game)
{
	int	width;
	int	height;

	game->img_collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/coins.xpm", &width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm",
			&width, &height);
	game->img_surface = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/surface.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/exit.xpm",
			&width, &height);
	if (!game ->img_exit || !game->img_collectible || !game->img_wall
		|| !game->img_player || !game->img_surface)
	{
		ft_putstr_fd("Can't convert the XPM file to image \n", 1);
		close_win(game);
	}
}

void	display_images(t_game *game, int i)
{
	int	j;

	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->img_wall, j * 50, i * 50);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->img_player, j * 50, i * 50);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->img_collectible, j * 50, i * 50);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->img_surface, j * 50, i * 50);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->img_exit, j * 50, i * 50);
		}
	}
}

int	close_win(t_game *game)
{
	free_map(game->map);
	free_map(game->map2);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	if (game->img_surface)
		mlx_destroy_image(game->mlx_ptr, game->img_surface);
	if (game->img_wall)
		mlx_destroy_image(game->mlx_ptr, game->img_wall);
	if (game ->img_player)
		mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (game ->img_collectible)
		mlx_destroy_image(game->mlx_ptr, game->img_collectible);
	if (game -> img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	exit(0);
	return (0);
}

void	free_map(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			free_map(game->map);
		if (game->map2)
			free_map(game->map2);
		free(game);
	}
	return ;
}
