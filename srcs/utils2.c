/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:15:39 by mlouati           #+#    #+#             */
/*   Updated: 2024/07/31 11:40:11 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game, int *nb_moves)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y][game->player_x + 1] == 'C')
			game->collectible--;
		if (game->map[game->player_y][game->player_x + 1] == 'E'
			&& game->collectible != 0)
			return ;
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_surface,
			game->player_x * 50, game->player_y * 50);
		game->map[game->player_y][game->player_x] = '0';
		game->player_x++;
		if (game->collectible == 0
			&& game->map[game->player_y][game->player_x] == 'E')
		{
			ft_putstr_fd("you win \n", 1);
			close_win(game);
		}
		game->map[game->player_y][game->player_x] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player,
			(game->player_x) * 50, (game->player_y) * 50);
		(*nb_moves)++;
		ft_putstr_fd("moves : ", 1);
		ft_putnbr_fd(*nb_moves, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	move_left(t_game *game, int *nb_moves)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
			game->collectible--;
		if (game->map[game->player_y][game->player_x - 1] == 'E'
			&& game->collectible != 0)
			return ;
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_surface,
			game->player_x * 50, game->player_y * 50);
		game->map[game->player_y][game->player_x] = '0';
		game->player_x--;
		if (game->collectible == 0
			&& game->map[game->player_y][game->player_x] == 'E')
		{
			ft_putstr_fd("you win \n", 1);
			close_win(game);
		}
		game->map[game->player_y][game->player_x] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player,
			(game->player_x) * 50, (game->player_y) * 50);
		(*nb_moves)++;
		ft_putstr_fd("moves : ", 1);
		ft_putnbr_fd(*nb_moves, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	move_up(t_game *game, int *nb_moves)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x] == 'C')
			game->collectible--;
		if (game->map[game->player_y - 1][game->player_x] == 'E'
			&& game->collectible != 0)
			return ;
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_surface,
			game->player_x * 50, game->player_y * 50);
		game->map[game->player_y][game->player_x] = '0';
		game->player_y--;
		if (game->collectible == 0
			&& game->map[game->player_y][game->player_x] == 'E')
		{
			ft_putstr_fd("you win \n", 1);
			close_win(game);
		}
		game->map[game->player_y][game->player_x] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player,
			(game->player_x) * 50, (game->player_y) * 50);
		(*nb_moves)++;
		ft_putstr_fd("moves : ", 1);
		ft_putnbr_fd(*nb_moves, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	move_down(t_game *game, int *nb_moves)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		if (game->map[game->player_y + 1][game->player_x] == 'E'
			&& game->collectible != 0)
			return ;
		if (game->map[game->player_y + 1][game->player_x] == 'C')
			game->collectible--;
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_surface,
			game->player_x * 50, game->player_y * 50);
		game->map[game->player_y][game->player_x] = '0';
		game->player_y++;
		if (game->collectible == 0
			&& game->map[game->player_y][game->player_x] == 'E')
		{
			ft_putstr_fd("you win \n", 1);
			close_win(game);
		}
		game->map[game->player_y][game->player_x] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player,
			(game->player_x) * 50, (game->player_y) * 50);
		(*nb_moves)++;
		ft_putstr_fd("moves : ", 1);
		ft_putnbr_fd(*nb_moves, 1);
		ft_putstr_fd("\n", 1);
	}
}

int	ft_move(int keycode, t_game *game)
{
	static int	nb_moves;

	if (keycode == 65307 || keycode == 113)
		close_win(game);
	if (keycode == 100 || keycode == 65363)
		move_right(game, &nb_moves);
	else if (keycode == 97 || keycode == 65361)
		move_left(game, &nb_moves);
	else if (keycode == 119 || keycode == 65362)
		move_up(game, &nb_moves);
	else if (keycode == 115 || keycode == 65364)
		move_down(game, &nb_moves);
	return (0);
}
