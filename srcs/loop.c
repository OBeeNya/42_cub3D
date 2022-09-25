/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:12:26 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/23 11:48:58 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_step_and_sidedist(t_init *init, double *stepX, double *stepY)
{
	if (init->game->raydirx < 0)
	{
		*stepX = -1;
		init->game->sidedistx = (init->game->posx - init->game->mapx)
			* init->game->deltadistx;
	}
	else
	{
		*stepX = 1;
		init->game->sidedistx = (init->game->mapx + 1.0 - init->game->posx)
			* init->game->deltadistx;
	}
	if (init->game->raydiry < 0)
	{
		*stepY = -1;
		init->game->sidedisty = (init->game->posy - init->game->mapy)
			* init->game->deltadisty;
	}
	else
	{
		*stepY = 1;
		init->game->sidedisty = (init->game->mapy + 1.0 - init->game->posy)
			* init->game->deltadisty;
	}
}

void	ft_dda(t_init *init, int *side, double stepX, double stepY)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (init->game->sidedistx < init->game->sidedisty)
		{
			init->game->sidedistx += init->game->deltadistx;
			init->game->mapx += (int)stepX;
			*side = 0;
		}
		else
		{
			init->game->sidedisty += init->game->deltadisty;
			init->game->mapy += (int)stepY;
			*side = 1;
		}
		if (init->map[init->game->mapy][init->game->mapx] == '1')
			hit++;
	}
}

void	ft_perp_dist(t_init *init, int side, int stepx, int stepy)
{
	if (!side)
		init->game->perpwalldist = ((double)init->game->mapx - \
				init->game->posx + (1 - stepx) / 2) / init->game->raydirx;
	else
		init->game->perpwalldist = ((double)init->game->mapy - \
				init->game->posy + (1 - stepy) / 2) / init->game->raydiry;
}

void	ft_init_vectors(t_init *init, int i)
{
	init->game->camerax = 2 * i / (double)init->width - 1;
	init->game->raydirx = init->game->dirx + init->game->planex
		* init->game->camerax;
	init->game->raydiry = init->game->diry + init->game->planey
		* init->game->camerax;
	init->game->mapx = (int)init->game->posx;
	init->game->mapy = (int)init->game->posy;
	if (!init->game->raydiry)
		init->game->deltadistx = 0;
	else if (!init->game->raydirx)
		init->game->deltadistx = 1;
	else
		init->game->deltadistx = sqrt(1 + pow(init->game->raydiry, 2) \
		/ pow(init->game->raydirx, 2));
	if (!init->game->raydirx)
		init->game->deltadisty = 0;
	else if (!init->game->raydiry)
		init->game->deltadisty = 1;
	else
		init->game->deltadisty = sqrt(1 + pow(init->game->raydirx, 2) \
		/ pow(init->game->raydiry, 2));
}

int	ft_game_loop(t_init *init)
{
	int		i;
	int		side;
	double	stepx;
	double	stepy;

	i = 0;
	while (i < init->width)
	{
		ft_init_vectors(init, i);
		ft_step_and_sidedist(init, &stepx, &stepy);
		ft_dda(init, &side, stepx, stepy);
		ft_perp_dist(init, side, stepx, stepy);
		ft_draw_vertical_line(init, i, side);
		i++;
	}
	mlx_put_image_to_window(init->mlx, init->win, init->img, 0, 0);
	return (0);
}
