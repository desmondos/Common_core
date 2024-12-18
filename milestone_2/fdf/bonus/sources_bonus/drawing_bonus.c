/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:02 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 12:14:56 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	drawing(t_fdf *fdf, t_dot *proj, int fit)
{
	if (fit)
		screen_coordinates(fdf, proj);
	if (fdf->map.is_lines)
		render_wireframe(fdf, proj);
	if (fdf->map.is_dots)
		draw_painted_dots(fdf, proj);
}

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

static void	update_dot(t_fdf *fdf, int line_nbr, int index)
{
	fdf->map.dots[index].ax[2] = ft_atoi(fdf->splits[fdf->pos]);
	fdf->map.dots[index].ax[0] = fdf->pos - fdf->map.lim.ax[0] / 2;
	fdf->map.dots[index].ax[1] = line_nbr - fdf->map.lim.ax[1] / 2;
	fdf->map.dots[index].is_paint = 1;
	fdf->map.dots[index].color = DEFAULT;
	fdf->map.dots[index].hexa_color = parse_hexaco(fdf->splits[fdf->pos]);
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
	fdf->splits = ft_split(line, ' ');
	if (!fdf->splits)
	{
		puterror("error at import dots");
		return (1);
	}
	fdf->pos = 0;
	while (fdf->splits[fdf->pos] && fdf->splits[fdf->pos][0] != '\n')
	{
		check_invalid_dots(fdf, index);
		update_dot(fdf, line_nbr, index);
		fdf->pos++;
		index++;
	}
	free_str_array(fdf->splits);
	return (fdf->pos);
}

void	extract_dots(t_fdf *fdf)
{
	static int	num_dots = 0;
	static int	num_line = 0;
	int			pos;

	fdf->last = fdf->map.mem;
	fdf->line = NULL;
	pos = 0;
	fdf->map.dots = ft_calloc(fdf->map.length, sizeof(t_dot));
	if (!fdf->map.dots)
		puterror("error at seg_algo map_get_dots");
	while (++pos)
	{
		if (fdf->map.mem[pos] == '\n' || fdf->map.mem[pos] == '\0')
		{
			free(fdf->line);
			fdf->line = ft_substr(fdf->last, 0, &fdf->map.mem[pos] - fdf->last);
			if (!fdf->line)
				handle_map_alloc(fdf);
			fdf->last = &fdf->map.mem[pos + 1];
			num_dots += import_dots(fdf->line, fdf, num_line++);
			if (fdf->map.mem[pos] == '\0')
				break ;
		}
	}
	free(fdf->line);
}
