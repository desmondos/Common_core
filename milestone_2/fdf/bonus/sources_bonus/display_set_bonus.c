/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_set_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:00:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 12:14:34 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	screen_coordinates(t_fdf *fdf, t_dot *projected_dots)
{
	fdf->map.from.ax[0] = (WIN_WIDTH / 4);
	fdf->map.from.ax[1] = WIN_HEIGHT / 4;
	fdf->map.from.ax[2] = 0;
	fdf->map.scale = 0.1;
	copy_map(fdf->map.dots, projected_dots, fdf->map.length);
	transform_points(fdf, projected_dots);
	while (!(check_limits(projected_dots, fdf->map.length)))
	{
		fdf->map.from.ax[0] = (WIDTH / 2);
		fdf->map.from.ax[1] = HEIGHT / 2;
		copy_map(fdf->map.dots, projected_dots, fdf->map.length);
		transform_points(fdf, projected_dots);
		fdf->map.scale += 0.1;
	}
}

void	copy_map(t_dot *from, t_dot *to, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		to[pos] = from[pos];
		pos++;
	}
}

void	transform_points(t_fdf *fdf, t_dot *proj)
{
	divide_z_coordinate(proj, fdf->map.divide_z, fdf->map.length);
	apply_new_z(proj, fdf->map.length, fdf->map.brange);
	if (fdf->map.is_geom)
	{
		set_sphere_view(&fdf->map, proj);
		if (fdf->map.is_shad)
			set_paint_status(proj, fdf->map.length);
	}
	rotate_around_x(proj, proj, fdf->map.angle[0], fdf->map.length);
	rotate_around_y(proj, proj, fdf->map.angle[1], fdf->map.length);
	rotate_around_z(proj, proj, fdf->map.angle[2], fdf->map.length);
	ortho_projection(proj, proj, fdf->map.length);
	apply_scale(proj, fdf->map.scale, fdf->map.length);
	apply_translation(proj, fdf->map.from, fdf->map.length);
}

void	apply_scale(t_dot *dots, int scale, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		dots[pos].ax[0] *= scale;
		dots[pos].ax[1] *= scale;
		dots[pos].ax[2] *= scale;
		pos++;
	}
}

void	apply_translation(t_dot *dots, t_dot translation, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		dots[pos].ax[0] += translation.ax[0];
		dots[pos].ax[1] += translation.ax[1];
		dots[pos].ax[2] += translation.ax[2];
		pos++;
	}
}
