/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:02 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 23:40:11 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	draw_fdf(t_fdf *fdf, int sized)
{
	t_dot	*proj;

	proj = malloc(fdf->map.length * sizeof(t_dot));
	if (proj == NULL)
		puterror("alloc error");
	fdf->map.render++;
	set_background_color(fdf, fdf->map.colors.backco);
	if (fdf->map.dots != NULL)
	{
		copy_map(fdf->map.dots, proj, fdf->map.length);
		transform_points(fdf, proj);
		drawing(fdf, proj, sized);
		mlx_put_image_to_window(fdf->set.mlx, fdf->set.win,
			fdf->bg_map.img, 0, 0);
	}
	else
	{
		free(proj);
		puterror("error mem");
	}
	free(proj);
	return (0);
}

static int	init_import_dots(char *line, t_fdf *fdf)
{
	fdf->splits = ft_split(line, 32);
	if (!fdf->splits)
	{
		puterror("errorr at import_dots");
		return (1);
	}
	fdf->pos = 0;
	return (0);
}

static void	process_dots(t_fdf *fdf, int index, int line_nbr)
{
	check_invalid_dots(fdf, index);
	fdf->map.dots[index].ax[2] = ft_atoi(fdf->splits[fdf->pos]);
	fdf->map.dots[index].ax[0] = fdf->pos - fdf->map.lim.ax[0] / 2;
	fdf->map.dots[index].ax[1] = line_nbr - fdf->map.lim.ax[1] / 2;
	fdf->map.dots[index].is_paint = 1;
	fdf->map.dots[index].color = DEFAULT;
	fdf->map.dots[index].hexa_color = parse_hexaco(fdf->splits[fdf->pos]);
}

static void	update_limits(t_fdf *fdf, int index)
{
	if (fdf->map.lim.ax[2] < fdf->map.dots[index].ax[2])
		fdf->map.lim.ax[2] = fdf->map.dots[index].ax[2];
	if (fdf->map.min_z > fdf->map.dots[index].ax[2])
		fdf->map.min_z = fdf->map.dots[index].ax[2];
}

int	import_dots(char *line, t_fdf *fdf, int line_nbr)
{
	static int	index = 0;

	if (line_nbr == 0)
		index = 0;
	if (init_import_dots(line, fdf))
		return (1);
	while (fdf->splits[fdf->pos])
	{
		process_dots(fdf, index, line_nbr);
		update_limits(fdf, index);
		fdf->pos++;
		index++;
	}
	free_str_array(fdf->splits);
	return (fdf->pos);
}
