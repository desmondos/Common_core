/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:05:42 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 12:16:16 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static int	read_file_content(int fd, t_fdf *fdf)
{
	static int	byte_readed = READ;
	static int	tot_bytes = READ;

	byte_readed = read(fd, fdf->buf, READ);
	while (byte_readed > 0)
	{
		fdf->buf[byte_readed] = '\0';
		fdf->stash = fdf->maps;
		fdf->maps = ft_strjoin(fdf->maps, fdf->buf);
		if (!fdf->maps)
		{
			free(fdf->stash);
			terminate_with_error("read");
			return (0);
		}
		free(fdf->stash);
		tot_bytes += byte_readed;
		byte_readed = read(fd, fdf->buf, READ);
	}
	if (byte_readed < 0)
	{
		terminate_with_error("reading");
		return (0);
	}
	return (1);
}

static int	allocate_buff(t_fdf *fdf)
{
	fdf->buf = malloc(READ + 1);
	if (!fdf->buf)
	{
		terminate_with_error("failed to allocate buf");
		return (0);
	}
	fdf->maps = ft_strdup("");
	if (!fdf->maps)
	{
		free(fdf->buf);
		terminate_with_error("failed to alloc");
		return (0);
	}
	return (1);
}

char	*read_file(int fd, t_fdf *fdf)
{
	if (!allocate_buff(fdf))
		return (NULL);
	if (!read_file_content(fd, fdf))
	{
		free(fdf->buf);
		free(fdf->maps);
		return (NULL);
	}
	free(fdf->buf);
	return (fdf->maps);
}

void	map_size(t_map *map)
{
	static int	pos = 0;
	static int	elem = 0;

	while (map->mem[pos])
	{
		if (map->mem[pos] == '\n' && map->mem[pos + 1] == '\0')
			break ;
		if (ft_isalnum(map->mem[pos]) && (map->mem[pos + 1] == ' '
				|| map->mem[pos + 1] == '\n' || map->mem[pos + 1] == '\0'))
			elem++;
		if (map->mem[pos] == '\n')
		{
			map->lim.ax[1]++;
			if (map->lim.ax[0] != 0 && (map->lim.ax[0] != elem))
				return ;
			else
				map->lim.ax[0] = elem;
			elem = 0;
		}
		pos++;
	}
	if (elem > 0 && (map->lim.ax[0] != elem))
		return ;
	map->lim.ax[1]++;
	map->length = map->lim.ax[0] * map->lim.ax[1];
}

int	check_limits(t_dot *dots, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		if (dots[pos].ax[0] > WIN_WIDTH - MARGIN)
			return (1);
		if (dots[pos].ax[1] < MARGIN
			|| dots[pos].ax[1] > (WIN_HEIGHT - MARGIN))
			return (1);
		pos++;
	}
	return (0);
}
