/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:03:10 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 12:23:32 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_isometric_view(t_map *map)
{
	map->is_geom = 0;
	map->brange = 0;
	map->angle[0] = 45;
	map->angle[1] = 35;
	map->angle[2] = 331;
	map->from.ax[0] = WIN_WIDTH / 2;
	map->from.ax[1] = WIN_HEIGHT / 2;
}

void	set_top_view(t_map *map)
{
	map->is_geom = 0;
	map->brange = 0;
	map->angle[0] = 0;
	map->angle[1] = 0;
	map->angle[2] = 0;
	map->from.ax[0] = (WIN_WIDTH / 2);
	map->from.ax[1] = (WIN_HEIGHT / 2);
}

void	set_profil_view(t_map *map)
{
	map->is_geom = 0;
	map->brange = 0;
	map->angle[0] = 90;
	map->angle[1] = 0;
	map->angle[2] = 0;
	map->from.ax[0] = (WIN_WIDTH / 2);
	map->from.ax[1] = (WIN_HEIGHT / 2);
}

void	set_sphere_view(t_map *map, t_dot *dots)
{
	int		pos;

	pos = 0;
	while (pos < map->length)
	{
		dots[pos].ax[0] = (map->rad + dots[pos].ax[2])
			* cos(dots[pos].pol[LONG]) * sin(dots[pos].pol[LAT]);
		dots[pos].ax[1] = (map->rad + dots[pos].ax[2])
			* sin(dots[pos].pol[LONG]) * sin(dots[pos].pol[LAT]);
		dots[pos].ax[2] = (map->rad + dots[pos].ax[2])
			* cos(dots[pos].pol[LAT]);
		pos++;
	}
}

void	set_polar(t_map *map)
{
	int		pos;
	float	x_moves;
	float	y_moves;

	x_moves = (M_PI * 2) / (map->lim.ax[0] - 1);
	y_moves = (M_PI / (map->lim.ax[1]));
	map->rad = map->lim.ax[0] / (M_PI * 2);
	pos = 0;
	while (pos < map->length)
	{
		map->dots[pos].pol[LONG] = -(map->dots[pos].ax[0]) * x_moves;
		if (map->dots[pos].ax[1] > 0)
			map->dots[pos].pol[LAT] = ((map->dots[pos].ax[1])
					+ (map->lim.ax[1] / 2)) * y_moves - 0.5 * y_moves;
		map->dots[pos].pol[LAT] = (map->dots[pos].ax[1]
				+ (map->lim.ax[1] / 2) - 1) * y_moves + 0.5 * y_moves;
		pos++;
	}
}
