/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:11:42 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/23 12:08:01 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_check_col_norme(char *line, size_t i, char **elements, t_init *init)
{
	if (line[i] && line[i] != '\n')
	{
		ft_free_col_param(line, elements, init);
		return (0);
	}
	return (1);
}

void	ft_first_chars(size_t *i, size_t *j, char *line)
{
	*i = 0;
	while (line[*i] == ' ')
		(*i)++;
	*j = *i;
	(*i)++;
}

void	ft_dispatch_map_func(char *filepath, int fd, int nb, t_init *init)
{
	ft_cpy_map_lines(filepath, fd, nb, init);
	ft_check_map(init);
}

void	ft_move_camera_left(t_init *init, t_game *game, \
double prevplanex, double prevdirx)
{
	if (init->moves.camera_l == 1)
	{
		game->dirx = game->dirx * cos(-(game->rotspeed / 2)) - game->diry \
			* sin(-(game->rotspeed) / 2);
		game->diry = prevdirx * sin(-(game->rotspeed / 2)) + game->diry \
			* cos(-(game->rotspeed) / 2);
		game->planex = game->planex * cos(-(game->rotspeed) / 2) \
			- game->planey * sin(-(game->rotspeed) / 2);
		game->planey = prevplanex * sin(-(game->rotspeed) / 2) + game->planey \
			* cos(-(game->rotspeed / 2));
	}
}

void	ft_move_camera(t_init *init, t_game *game)
{
	double	prevplanex;
	double	prevdirx;
	double	oldplanex;

	prevplanex = game->planex;
	prevdirx = game->dirx;
	if (init->moves.camera_r == 1)
	{
		prevdirx = game->dirx;
		oldplanex = game->planex;
		game->dirx = game->dirx * cos(game->rotspeed / 2) - game->diry \
			* sin(game->rotspeed / 2);
		game->diry = prevdirx * sin(game->rotspeed / 2) + game->diry \
			* cos(game->rotspeed / 2);
		game->planex = game->planex * cos(game->rotspeed / 2) - game->planey \
			* sin(game->rotspeed / 2);
		game->planey = oldplanex * sin(game->rotspeed / 2) + game->planey \
			* cos(game->rotspeed / 2);
	}
	ft_move_camera_left(init, game, prevplanex, prevdirx);
}
