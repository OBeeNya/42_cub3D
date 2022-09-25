/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:12:49 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/23 11:52:56 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_init_moves(t_init *init)
{
	init->moves.move_f = 0;
	init->moves.move_b = 0;
	init->moves.move_r = 0;
	init->moves.move_l = 0;
	init->game->movespeed = 0.1;
	init->game->rotspeed = 0.1;
}

void	ft_move_forward(t_init *init, t_game *game)
{
	if (init->moves.move_f == 1)
	{
		if (init && init->map && init->map[(int)game->posy]
			&& init->map[(int)game->posy]
			[(int)(game->posx + game->dirx * game->movespeed * 2)]
			&& init->map[(int)game->posy]
			[(int)(game->posx + game->dirx * game->movespeed * 2)] == '0')
			game->posx += game->dirx * game->movespeed;
		if (init && init->map
			&& init->map[(int)(game->posy + game->diry * game->movespeed * 2)]
			&& init->map[(int)(game->posy + game->diry * game->movespeed * 2)]
			[(int)game->posx]
			&& init->map[(int)(game->posy + game->diry * game->movespeed * 2)]
			[(int)game->posx] == '0')
			game->posy += game->diry * game->movespeed;
	}
}

void	ft_move_backward(t_init *init, t_game *game)
{
	if (init->moves.move_b == 1)
	{
		if (init && init->map && init->map[(int)game->posy]
			&& init->map[(int)game->posy]
			[(int)(game->posx - game->dirx * game->movespeed * 2)]
			&& init->map[(int)game->posy]
			[(int)(game->posx - game->dirx * game->movespeed * 2)] == '0')
			game->posx -= game->dirx * game->movespeed;
		if (init && init->map
			&& init->map[(int)(game->posy - game->diry * game->movespeed * 2)]
			&& init->map[(int)(game->posy - game->diry * game->movespeed * 2)]
			[(int)game->posx]
			&& init->map[(int)(game->posy - game->diry * game->movespeed * 2)]
			[(int)game->posx] == '0')
			game->posy -= game->diry * game->movespeed;
	}
}

void	ft_move_right(t_init *init, t_game *game)
{
	if (init->moves.move_r == 1)
	{
		if (init && init->map && init->map[(int)game->posy]
			&& init->map[(int)game->posy]
			[(int)(game->posx - game->diry * game->movespeed * 2)]
			&& init->map[(int)game->posy]
			[(int)(game->posx - game->diry * game->movespeed * 2)] == '0')
			game->posx -= game->diry * game->movespeed;
		if (init && init->map && init->map[(int)game->posx]
			&& init->map[(int)(game->posy + game->dirx * game->movespeed * 2)]
			[(int)game->posx]
			&& init->map[(int)(game->posy + game->dirx * game->movespeed * 2)]
			[(int)game->posx] == '0')
			game->posy += game->dirx * game->movespeed;
	}
}

void	ft_move_left(t_init *init, t_game *game)
{
	if (init->moves.move_l == 1)
	{
		if (init && init->map && init->map[(int)game->posy]
			&& init->map[(int)game->posy]
			[(int)(game->posx + game->diry * game->movespeed * 2)]
			&& init->map[(int)game->posy]
			[(int)(game->posx + game->diry * game->movespeed * 2)] == '0')
			game->posx += game->diry * game->movespeed;
		if (init && init->map
			&& init->map[(int)(game->posy - game->dirx * game->movespeed * 2)]
			&& init->map[(int)(game->posy - game->dirx * game->movespeed * 2)]
			[(int)game->posx]
			&& init->map[(int)(game->posy - game->dirx * game->movespeed * 2)]
			[(int)game->posx] == '0')
			game->posy -= game->dirx * game->movespeed;
	}
}
