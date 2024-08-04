/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:22:20 by mlouati           #+#    #+#             */
/*   Updated: 2024/08/04 10:59:14 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	char	**map2;
	int		rows;
	int		colons;
	int		collectible;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		exit_v;
	int		count_p;
	int		count_e;
	void	*img_player;
	void	*img_collectible;
	void	*img_wall;
	void	*img_surface;
	void	*img_exit;
}			t_game;

void		init_game(t_game *game);
void		error_msg(t_game *game, int nb);
void		flood_fill(t_game *game, int x, int y, int *count);
void		check_chemin(t_game *game);
void		free_map(char **s);
void		free_game(t_game *game);
void		check_elements(t_game *game, int i, int j);
void		convert_to_image(t_game *game);
void		display_images(t_game *game, int i);

int			close_win(t_game *game);
int			ft_move(int keycode, t_game *game);
void		move_right(t_game *game, int *nb_moves);
void		move_left(t_game *game, int *nb_moves);
void		move_up(t_game *game, int *nb_moves);
void		move_down(t_game *game, int *nb_moves);

void		check_content(t_game *game);
void		check_edge(t_game *game);
void		check_form(t_game *game);
void		check_map2(t_game *game, char *s);
void		free_s_line(t_game *game, char *s, char *line, int fd);
void		check_extension(t_game *game, char *s);
void		init_game(t_game *game);
void		check_s(t_game *game, char *s);
void		check_size(t_game *game);

#endif