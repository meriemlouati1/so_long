/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:55:22 by mlouati           #+#    #+#             */
/*   Updated: 2024/08/04 10:59:46 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map2(t_game *game, char *s)
{
	check_s(game, s);
	game->map = ft_split(s, '\n');
	game->map2 = ft_split(s, '\n');
	free(s);
	check_form(game);
	check_edge(game);
	check_content(game);
	check_chemin(game);
	check_size(game);
}

void	check_map(t_game *game, char *str)
{
	char	*line;
	char	*s;
	int		fd;

	fd = open(str, O_RDONLY, 0777);
	if (fd == -1)
		error_msg(game, 2);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error_msg(game, 3);
	}
	s = ft_strdup("");
	while (line)
	{
		if (line [0] == '\n')
			free_s_line(game, s, line, fd);
		s = ft_strjoin(s, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_map2(game, s);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		error_msg(game, 0);
	check_extension(game, argv[1]);
	game = (t_game *)malloc(sizeof(t_game));
	init_game(game);
	check_map(game, argv[1]);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		free_game(game);
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->colons * 50, game->rows
			* 50, "so_long");
	if (!game->mlx_win)
	{
		free(game->mlx_ptr);
		free_game(game);
	}
	convert_to_image(game);
	display_images(game, -1);
	mlx_key_hook(game->mlx_win, ft_move, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, close_win, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
