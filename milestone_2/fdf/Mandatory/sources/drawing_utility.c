/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:02 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 23:12:17 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	drawing(t_fdf *fdf, t_dot *proj, int fit)
{
	if (fit)
		screen_coordinates(fdf, proj);
	if (fdf->map.is_lines)
		render_wireframe(fdf, proj);
	if (fdf->map.is_dots)
		draw_painted_dots(fdf, proj);
}

int	import_map(t_fdf *fdf, char *filepath)
{
	int	fd;

	initialize_map(&fdf->map, 1);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (puterror("open file failed"), 1);
	fdf->map.mem = read_file(fd, fdf);
	if (fdf->map.mem == NULL)
		return (puterror("read file failed."), close(fd), 1);
	else
	{
		map_size(&fdf->map);
		extract_dots(fdf);
		apply_color(&fdf->map);
		set_polar(&fdf->map);
		if (fdf->map.dots == NULL)
			return (puterror("failed to generate dots"),
				free(fdf->map.mem), fdf->map.mem = NULL, close(fd), 1);
	}
	close(fd);
	return (0);
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
