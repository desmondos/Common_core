/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:56:41 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 17:17:27 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	initialize_mlx_utils(t_fdf *fdf)
{
	fdf->bg_map.img = mlx_new_image(fdf->set.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (fdf->bg_map.img == NULL)
	{
		mlx_destroy_window(fdf->set.mlx, fdf->set.win);
		mlx_destroy_display(fdf->set.mlx);
		free(fdf->set.mlx);
		free(fdf->map.dots);
		puterror("mlx_new_image() failed");
		return ;
	}
	fdf->bg_map.buffer = mlx_get_data_addr(fdf->bg_map.img, &fdf->bg_map.bpix,
			&fdf->bg_map.lines, &fdf->bg_map.endi);
	if (fdf->bg_map.buffer == NULL)
	{
		mlx_destroy_image(fdf->set.mlx, fdf->bg_map.img);
		mlx_destroy_window(fdf->set.mlx, fdf->set.win);
		free(fdf->map.dots);
		puterror("mlx_get_addr() failed");
		return ;
	}
}

void	initialize_mlx(t_fdf *fdf)
{
	fdf->set.mlx = mlx_init();
	if (fdf->set.mlx == NULL)
	{
		free(fdf->map.dots);
		puterror("mlx_init() failed");
		return ;
	}
	fdf->set.win = mlx_new_window(fdf->set.mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (fdf->set.win == NULL)
	{
		mlx_destroy_display(fdf->set.mlx);
		free(fdf->set.mlx);
		free(fdf->map.dots);
		puterror("mlx_new_window() failed");
		return ;
	}
}

void	initialize_variables(t_fdf *fdf)
{
	fdf->map.render = 1;
	fdf->map.scale = 0.001;
	fdf->map.dots = malloc(fdf->map.length * sizeof(t_dot));
	if (!fdf->map.dots)
		terminate_with_error("mem alloc failed for map");
	fdf->map.alt = 0.4;
	fdf->mouse.is_leftmouse = 0;
	fdf->map.lim.ax[0] = 1;
	fdf->map.lim.ax[2] = 1;
	fdf->key.leftctrl = 0;
	fdf->key.rightctrl = 0;
}

int	check_drawing(t_fdf *fdf)
{
	if (draw_fdf(fdf, SIZED) < 0)
	{
		puterror("error drawing map");
		clean_fdf_struct(fdf);
		return (1);
	}
	return (0);
}

int	import_map_check(t_fdf *fdf, char *filepath)
{
	if (import_map(fdf, filepath) < 0)
	{
		puterror("error importing map");
		clean_fdf_struct(fdf);
		return (1);
	}
	return (0);
}
