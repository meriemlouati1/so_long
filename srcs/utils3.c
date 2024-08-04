/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:24:51 by mlouati           #+#    #+#             */
/*   Updated: 2024/08/04 10:59:37 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(t_game *game, char *s)
{
	int	len;

	len = ft_strlen(s);
	if (ft_strncmp(".ber", s + len - 4, 4)
		||!ft_strncmp("/.ber", s + len - 5, 5))
		error_msg(game, 1);
	return ;
}

void	init_game(t_game *game)
{
	game ->img_collectible = NULL;
	game ->img_surface = NULL;
	game ->img_player = NULL;
	game ->img_wall = NULL;
	game ->img_exit = NULL;
	game->mlx_ptr = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->map2 = NULL;
	game ->collectible = 0;
	game -> count_e = 0;
	game ->player_x = 0;
	game ->player_y = 0;
	game ->count_p = 0;
	game ->colons = 0;
	game ->exit_x = 0;
	game ->exit_y = 0;
	game ->exit_v = 0;
	game ->rows = 0;
}

void	check_s(t_game *game, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			if (!s[i + 1] || (s[i + 1] && s[i + 1] == '\n'))
			{
				free(s);
				error_msg(game, 4);
			}
		}
		i++;
	}
}

void	free_s_line(t_game *game, char *s, char *line, int fd)
{
	if (s)
		free(s);
	if (line)
		free(line);
	close(fd);
	error_msg(game, 4);
}

void	check_size(t_game *game)
{
	if (game ->colons * 50 > 1920)
		error_msg(game, 8);
	if (game ->rows * 50 > 1080)
		error_msg(game, 9);
}
