/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_tools_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:02 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 12:17:44 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	key_press(int keycode, t_fdf *fdf)
{
	handle_angle_control(keycode, fdf);
	handle_tools_one(keycode, fdf);
	handle_tools_two(keycode, fdf);
	handle_tools_three(keycode, fdf);
	draw_fdf(fdf, 0);
	return (0);
}

int	key_release(int keycode, t_fdf *fdf)
{
	if (keycode == CTRL_R || keycode == CTRL_L)
	{
		fdf->key.leftctrl = 0;
		fdf->key.rightctrl = 0;
	}
	return (0);
}

void	handle_tools_one(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		exit_program(fdf);
	if (keycode == K_R)
	{
		set_top_view(&fdf->map);
		draw_fdf(fdf, SIZED);
	}
	if (keycode == K_C)
	{
		fdf->map.from.ax[0] = (WIN_WIDTH / 2);
		fdf->map.from.ax[1] = (WIN_HEIGHT / 2);
	}
	if (keycode == K_P)
	{
		set_profil_view(&fdf->map);
		draw_fdf(fdf, SIZED);
	}
}

void	handle_tools_two(int keycode, t_fdf *fdf)
{
	if (keycode == K_D)
		fdf->map.is_dots = !fdf->map.is_dots;
	if (keycode == K_F)
		draw_fdf(fdf, SIZED);
	if (keycode == K_G)
		fdf->map.is_geom = !fdf->map.is_geom;
	if (keycode == K_H)
		fdf->map.is_shad = !fdf->map.is_shad;
	if (keycode == K_L)
		fdf->map.is_lines = !fdf->map.is_lines;
	if (keycode == K_X)
		fdf->map.is_suplines = !fdf->map.is_suplines;
}

void	handle_tools_three(int keycode, t_fdf *fdf)
{
	if (keycode == K_B)
		fdf->map.brange -= 0.0001;
	if (keycode == K_V)
		fdf->map.brange += 0.0001;
	if (keycode == K_SUM)
	{
		if (fdf->map.divide_z > 1)
			fdf->map.divide_z -= 0.1;
	}
	if (keycode == K_MIN)
		fdf->map.divide_z += 0.1;
	if (keycode == K_I)
	{
		set_isometric_view(&fdf->map);
		draw_fdf(fdf, SIZED);
	}
}
