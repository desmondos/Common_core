/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utility_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:02 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 12:15:12 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static int	open_file(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		puterror("open file failed");
	return (fd);
}

static int	read_map_memory(int fd, t_fdf *fdf)
{
	fdf->map.mem = read_file(fd, fdf);
	if (fdf->map.mem == NULL)
	{
		puterror("read file failed.");
		close(fd);
		return (1);
	}
	return (0);
}

static void	process_map(t_fdf *fdf)
{
	map_size(&fdf->map);
	extract_dots(fdf);
	apply_color(&fdf->map);
	set_polar(&fdf->map);
	if (fdf->map.dots == NULL)
	{
		puterror("failed to generate dots");
		free(fdf->map.mem);
		fdf->map.mem = NULL;
	}
}

int	import_map(t_fdf *fdf, char *filepath)
{
	int	fd;

	initialize_map(&fdf->map, 1);
	fd = open_file(filepath);
	if (fd < 0)
		return (1);
	if (read_map_memory(fd, fdf) != 0)
	{
		close(fd);
		return (1);
	}
	process_map(fdf);
	close(fd);
	return (0);
}
