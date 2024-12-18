/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:25:56 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 16:32:06 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (initialize_check(&fdf, argc, argv[1]) != 0)
		return (1);
	initialize_main(&fdf);
	if (import_map_check(&fdf, argv[1]) != 0)
	{
		clean_fdf_struct(&fdf);
		return (1);
	}
	check_drawing(&fdf);
	setup_hooks(&fdf);
	mlx_loop(fdf.set.mlx);
	clean_resources(&fdf);
	clean_fdf_struct(&fdf);
	return (0);
}

static int	process_line(t_fdf *fdf)
{
	fdf->length = 0;
	fdf->length = count_substr(fdf->line, 32);
	if (fdf->is_first_line)
	{
		fdf->first_line_len = fdf->length;
		fdf->map.length = fdf->first_line_len;
		fdf->is_first_line = 0;
	}
	if (fdf->length != fdf->first_line_len)
	{
		free(fdf->line);
		return (1);
	}
	fdf->map.height++;
	free(fdf->line);
	return (1);
}

int	count_dots(t_fdf *fdf, const char *filename)
{
	int	fd;

	fdf->map.height = 0;
	fdf->is_first_line = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		puterror("wrong or file doesn't exist.");
		return (1);
	}
	fdf->line = get_next_line(fd);
	while (fdf->line)
	{
		if (!process_line(fdf))
		{
			close(fd);
			free(fdf->line);
			return (1);
		}
		fdf->line = get_next_line(fd);
	}
	close(fd);
	return (fdf->map.length * fdf->map.height);
}

void	initialize_map(t_map *map, int sum)
{
	if (sum)
	{
		map->length = 0;
		map->lim.ax[0] = 0;
		map->lim.ax[1] = 0;
		map->lim.ax[2] = 0;
		map->min_z = 0;
	}
	map->is_lines = 1;
	map->scale = 0.01;
	map->is_geom = 0;
	map->brange = 0;
	map->divide_z = 1;
	map->is_dots = 0;
	map->is_suplines = 0;
	map->is_shad = 1;
	map->from.ax[0] = WIN_WIDTH / 2;
	map->from.ax[1] = WIN_HEIGHT / 2;
	map->from.ax[2] = 0;
	map->angle[0] = 52;
	map->angle[1] = 45;
	map->angle[2] = 331;
	initialize_color(map);
}

void	handle_map_alloc(t_fdf *fdf)
{
	free(fdf->map.dots);
	puterror("error memalloc");
}
