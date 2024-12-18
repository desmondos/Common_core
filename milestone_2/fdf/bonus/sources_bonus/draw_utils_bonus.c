/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:29:22 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 12:14:46 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	set_color(char *buff, int endian, int color, int transparency)
{
	if (endian == 1)
	{
		buff[0] = transparency;
		buff[1] = (color >> 16) & 0xFF;
		buff[2] = (color >> 8) & 0xFF;
		buff[3] = (color) & 0xFF;
	}
	else
	{
		buff[0] = (color) & 0xFF;
		buff[1] = (color >> 8) & 0xFF;
		buff[2] = (color >> 16) & 0xFF;
		buff[3] = transparency;
	}
}

int	put_pix(t_fdf *fdf, t_dot pix)
{
	int	pixel_pos;

	if (pix.ax[0] >= WIN_WIDTH || pix.ax[1] >= WIN_HEIGHT
		|| pix.ax[0] < 0 || pix.ax[1] < 0)
		return (-1);
	pixel_pos = ((int)pix.ax[1] * fdf->bg_map.lines) + ((int)pix.ax[0] * 4);
	if (fdf->bg_map.bpix != 32)
		pix.color = mlx_get_color_value(fdf->set.mlx, pix.color);
	set_color(&fdf->bg_map.buffer[pixel_pos], fdf->bg_map.endi, pix.color, 0);
	return (0);
}

void	draw_dot_aux(t_fdf *fdf, t_dot pixel, t_dot dot, int offset)
{
	int	pos;

	pos = dot.ax[0];
	while (pos <= dot.ax[0] + offset)
	{
		pixel.ax[0] = pos;
		pixel.ax[1] = (int)dot.ax[1] + offset;
		put_pix(fdf, pixel);
		pixel.ax[0] = pos;
		pixel.ax[1] = (int)dot.ax[1] - offset;
		put_pix(fdf, pixel);
		pos++;
	}
}

void	draw_dot(t_fdf *fdf, t_dot dot, int radius)
{
	int		is_radius_err;
	int		ax[2];
	int		mod[2];
	t_dot	pixel;

	ax[0] = radius;
	ax[1] = 0;
	mod[0] = 1 - (radius << 1);
	mod[1] = 0;
	is_radius_err = 0;
	pixel.color = dot.color;
	while (ax[0] >= ax[1])
	{
		draw_dot_aux(fdf, pixel, dot, ax[1]);
		draw_dot_aux(fdf, pixel, dot, ax[0]);
		ax[1]++;
		is_radius_err += mod[1];
		mod[1] += 2;
		if (((is_radius_err << 1) + mod[0]) > 0)
		{
			ax[0]--;
			is_radius_err += mod[0];
			mod[0] += 2;
		}
	}
}

void	draw_painted_dots(t_fdf *fdf, t_dot *dots)
{
	int	pos;

	pos = 0;
	while (pos < fdf->map.length)
	{
		if (dots[pos].is_paint)
			draw_dot(fdf, dots[pos], 1);
		pos++;
	}
}
