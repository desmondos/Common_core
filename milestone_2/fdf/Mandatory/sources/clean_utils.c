/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:00:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 21:03:59 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_double_pointer(void **str)
{
	void	**stash;

	if (str)
	{
		stash = str;
		while (*stash)
		{
			free(*stash);
			*stash = NULL;
			stash++;
		}
		free(str);
	}
}

void	free_str_array(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	clean_resources(t_fdf *fdf)
{
	if (fdf->bg_map.img != NULL)
	{
		mlx_destroy_image(fdf->set.mlx, fdf->bg_map.img);
		fdf->bg_map.img = NULL;
	}
	if (fdf->set.win != NULL)
	{
		mlx_destroy_window(fdf->set.mlx, fdf->set.win);
		fdf->set.win = NULL;
	}
	if (fdf->set.mlx != NULL)
	{
		mlx_destroy_display(fdf->set.mlx);
		free(fdf->set.mlx);
		fdf->set.mlx = NULL;
	}
	clean_fdf_struct(fdf);
}

void	clean_fdf_struct(t_fdf *fdf)
{
	if (fdf->map.dots)
	{
		free(fdf->map.dots);
		fdf->map.dots = NULL;
	}
	if (fdf->bg_map.img)
	{
		mlx_destroy_image(fdf->set.mlx, fdf->bg_map.img);
		fdf->bg_map.img = NULL;
	}
	if (fdf->set.win)
	{
		mlx_destroy_window(fdf->set.mlx, fdf->set.win);
		fdf->set.win = NULL;
	}
	if (fdf->set.mlx)
	{
		mlx_destroy_display(fdf->set.mlx);
		free(fdf->set.mlx);
		fdf->set.mlx = NULL;
	}
}

int	check_invalid_dots(t_fdf *fdf, int index)
{
	if (!is_valid_point(&fdf->splits[fdf->pos][0]))
	{
		free_str_array(fdf->splits);
		puterror("inv dot");
		return (1);
	}
	if (index >= fdf->map.length)
		return (1);
	return (0);
}
