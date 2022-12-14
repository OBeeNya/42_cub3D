/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:12:21 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/25 14:15:56 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_init_plane(t_init *init, char c)
{
	if (c == 'N')
	{
		init->game->planex = 1;
		init->game->planey = 0;
	}
	else if (c == 'W')
	{
		init->game->planex = 0;
		init->game->planey = -1;
	}
	else if (c == 'S')
	{
		init->game->planex = -1;
		init->game->planey = 0;
	}
	else if (c == 'E')
	{
		init->game->planex = 0;
		init->game->planey = 1;
	}
}

void	ft_init_dir(t_init *init, char c)
{
	if (c == 'N')
	{
		init->game->dirx = 0;
		init->game->diry = -1;
	}
	else if (c == 'W')
	{
		init->game->dirx = -1;
		init->game->diry = 0;
	}
	else if (c == 'S')
	{
		init->game->dirx = 0;
		init->game->diry = 1;
	}
	else if (c == 'E')
	{
		init->game->dirx = 1;
		init->game->diry = 0;
	}
}

void	ft_init_init(t_init *init)
{
	init->no = 0;
	init->so = 0;
	init->we = 0;
	init->ea = 0;
	init->f = 0;
	init->c = 0;
	init->fd = -1;
	init->textures[0].img = NULL;
	init->textures[1].img = NULL;
	init->textures[2].img = NULL;
	init->textures[3].img = NULL;
	init->img = NULL;
	init->win = NULL;
	init->game = ft_calloc(1, sizeof(t_game));
	if (!init->game)
		ft_error("Error\nMemory for init->game could not be allocated\n", init);
	init->game->time = 0;
	init->game->oldtime = 0;
	ft_init_moves(init);
}

void	ft_get_map_info(char *line, t_init *init)
{
	char	**elements;

	ft_check_spaces(line, init);
	elements = ft_split(line, " ");
	if (ft_strcmp("NO", elements[0]) && ft_strcmp("WE", elements[0])
		&& ft_strcmp("SO", elements[0]) && ft_strcmp("EA", elements[0])
		&& ft_strcmp("F", elements[0]) && ft_strcmp("C", elements[0]))
	{
		ft_free_split(elements);
		free(line);
		ft_error("Error\nInvalid identifier\n", init);
	}
	ft_orientation_id_cmp(elements, init, line);
	if (!ft_strcmp("C", elements[0]))
	{
		ft_check_color_parameters(line, init, elements);
		init->c++;
	}
	else if (!ft_strcmp("F", elements[0]))
	{
		ft_check_color_parameters(line, init, elements);
		init->f++;
	}
	ft_free_split(elements);
}

void	ft_open_fd(char *filepath, t_init *init)
{
	init->fd = open(filepath, O_DIRECTORY);
	if (init->fd != -1)
		ft_error("Error\nMap cannot be a directory\n", init);
	init->fd = open(filepath, O_RDONLY);
	if (init->fd == -1)
		ft_error("Error\nInvalid map file\n", init);
}
