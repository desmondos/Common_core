/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:26:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 16:34:24 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	initialize_check(t_fdf *fdf, int ac, char *filename)
{
	if (ac != 2)
	{
		puterror("usage: ./fdf <map.fdf or filepath>");
		return (1);
	}
	if (!is_fdf_extension(filename))
	{
		puterror("wrong or missing fdf extension");
		return (1);
	}
	if (file_exists(filename) == 1)
	{
		ft_printf("No file %s\n", filename);
		return (1);
	}
	if (count_dots(fdf, filename) == 1)
	{
		puterror("Found wrong line length. Exiting.");
		return (1);
	}
	return (0);
}

int	file_exists(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

void	initialize_main(t_fdf *fdf)
{
	initialize_variables(fdf);
	initialize_mlx(fdf);
	initialize_mlx_utils(fdf);
	free_variables(fdf);
}

void	free_variables(t_fdf *fdf)
{
	if (fdf->map.dots)
	{
		free(fdf->map.dots);
		fdf->map.dots = NULL;
	}
}

void	setup_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->set.win, key_press, fdf);
	mlx_hook(fdf->set.win, 2, 1L << 0, key_press, fdf);
	mlx_hook(fdf->set.win, 17, 0, exit_program, fdf);
}
