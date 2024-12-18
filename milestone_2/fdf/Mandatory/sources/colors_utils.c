/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:20:30 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 13:14:03 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	round_to_nearest(double value)
{
	if (value < 0)
		return ((int)(value - 0.5));
	return ((int)(value + 0.5));
}

int	interpolate_color(int start_co, int end_co, int length, int pix)
{
	int		new_co[3];
	double	inc[3];

	inc[0] = (double)((end_co >> 16) - (start_co >> 16)) / (double)length;
	inc[1] = (double)(((end_co >> 8) & 0xFF)
			- ((start_co >> 8) & 0xFF)) / (double)length;
	inc[2] = (double)((end_co & 0xFF) - (start_co & 0xFF)) / (double)length;
	new_co[0] = (start_co >> 16) + round_to_nearest(pix * inc[0]);
	new_co[1] = ((start_co >> 8) & 0xFF) + round_to_nearest(pix * inc[1]);
	new_co[2] = (start_co & 0xFF) + round_to_nearest(pix * inc[2]);
	return ((new_co[0] << 16) + (new_co[1] << 8) + new_co[2]);
}

int	convert_color(t_fdf *fdf, int color)
{
	if (fdf->bg_map.bpix != 32)
		color = mlx_get_color_value(fdf->set.mlx, color);
	return (color);
}

void	set_background_color(t_fdf *fdf, int bg_color)
{
	int	ax[2];
	int	pix;
	int	color;

	ax[0] = 0;
	ax[1] = 0;
	bg_color = convert_color(fdf, bg_color);
	while (ax[1] < WIN_HEIGHT)
	{
		while (ax[0] < WIN_WIDTH)
		{
			color = bg_color;
			pix = (ax[1] * fdf->bg_map.lines) + (ax[0] * 4);
			set_color(&fdf->bg_map.buffer[pix], fdf->bg_map.endi, color, 1);
			ax[0]++;
		}
		ax[1]++;
		ax[0] = 0;
	}
}
