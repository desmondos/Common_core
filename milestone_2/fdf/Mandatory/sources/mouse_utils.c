/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:05:42 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 12:23:13 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mouse_press(int mousecode, int x, int y, t_fdf *fdf)
{
	if (mousecode == 1)
	{
		fdf->mouse.is_leftmouse = 1;
		fdf->mouse.start_drag[0] = x;
		fdf->mouse.start_drag[1] = y;
	}
	if (mousecode == 4)
	{
		if (fdf->map.scale < MAX_ZOOM)
			fdf->map.scale *= ZOOM_FACTOR;
	}
	if (mousecode == 5)
	{
		if (fdf->map.scale > MIN_ZOOM)
			fdf->map.scale /= ZOOM_FACTOR;
	}
	draw_fdf(fdf, 0);
	return (0);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse.is_leftmouse)
	{
		fdf->delta_x = (x - fdf->mouse.start_drag[0]);
		fdf->delta_y = (y - fdf->mouse.start_drag[1]);
		fdf->map.from.ax[0] += fdf->delta_x;
		fdf->map.from.ax[1] += fdf->delta_y;
		fdf->mouse.start_drag[0] = x;
		fdf->mouse.start_drag[1] = y;
		draw_fdf(fdf, 0);
	}
	return (0);
}

int	mouse_drag(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse.is_leftmouse)
	{
		fdf->map.from.ax[0] += (x - fdf->mouse.start_drag[0]);
		fdf->map.from.ax[1] += (y - fdf->mouse.start_drag[1]);
		fdf->mouse.start_drag[0] = x;
		fdf->mouse.start_drag[1] = y;
		draw_fdf(fdf, 0);
	}
	return (0);
}

int	mouse_release(int mousecode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	(void)x;
	if (mousecode == 1)
		fdf->mouse.is_leftmouse = 0;
	return (0);
}
