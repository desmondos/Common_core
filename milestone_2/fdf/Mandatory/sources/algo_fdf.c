/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:34:31 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 21:11:01 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_paint_status(t_dot *dots, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		if (dots[pos].ax[2] < 0)
			dots[pos].is_paint = 0;
		else
			dots[pos].is_paint = 1;
		pos++;
	}
}

int	is_valid_pix(t_dot pix)
{
	if (pix.ax[0] < 0 || pix.ax[0] >= WIN_WIDTH)
		return (1);
	if (pix.ax[1] < 0 || pix.ax[1] >= WIN_HEIGHT)
		return (1);
	return (0);
}

int	draw_line(t_fdf *fdf, t_dot start, t_dot end)
{
	if (is_valid_pix(start) || is_valid_pix(end))
		return (1);
	fdf->discr.ax[0] = end.ax[0] - start.ax[0];
	fdf->discr.ax[1] = end.ax[1] - start.ax[1];
	fdf->pixels = sqrt((fdf->discr.ax[0] * fdf->discr.ax[0])
			+ (fdf->discr.ax[1] * fdf->discr.ax[1]));
	fdf->length = fdf->pixels;
	fdf->discr.ax[0] /= fdf->pixels;
	fdf->discr.ax[1] /= fdf->pixels;
	fdf->pix.ax[0] = start.ax[0];
	fdf->pix.ax[1] = start.ax[1];
	fdf->color.start_color = start.color;
	fdf->color.end_color = end.color;
	while (fdf->pixels >= 0)
	{
		fdf->pix.color = interpolate_color(fdf->color.start_color,
				fdf->color.end_color, fdf->length, (fdf->length - fdf->pixels));
		put_pix(fdf, fdf->pix);
		fdf->pix.ax[0] += fdf->discr.ax[0];
		fdf->pix.ax[1] += fdf->discr.ax[1];
		fdf->pixels--;
	}
	return (0);
}

void	create_wireframe(t_dot *dot, t_fdf *fdf, int density, int line)
{
	int	pos;
	int	end_x;
	int	end_y;

	pos = 0;
	while (pos < (int)fdf->map.lim.ax[0])
	{
		end_x = pos + density;
		if (end_x >= (int)fdf->map.lim.ax[0])
			end_x = (int)fdf->map.lim.ax[0] - 1;
		end_y = pos + (int)fdf->map.lim.ax[0] * density;
		if (dot[pos].is_paint)
		{
			draw_line(fdf, dot[pos], dot[end_x]);
			if (line + density < (int)fdf->map.lim.ax[1])
				draw_line(fdf, dot[pos], dot[end_y]);
		}
		pos += density;
	}
}

void	render_wireframe(t_fdf *fdf, t_dot *wire)
{
	int	pos;
	int	density;

	density = 1;
	if (density == 0)
		density = 1;
	pos = 0;
	while (pos < fdf->map.length)
	{
		create_wireframe(&wire[pos], fdf, density, (pos / fdf->map.lim.ax[0]));
		pos += fdf->map.lim.ax[0] * density;
	}
}
