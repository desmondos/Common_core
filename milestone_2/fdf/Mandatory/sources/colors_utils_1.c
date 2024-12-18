/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:00:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 21:07:49 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_color(t_map *map)
{
	int	pos;

	if (map->dots == NULL)
		puterror("error: map->dots is NULL");
	pos = 0;
	while (pos < map->length)
	{
		assign_color((int)map->lim.ax[2], map->min_z,
			&map->dots[pos], map->colors);
		pos++;
	}
}

void	assign_color(int max_h, int min_h, t_dot *dot, t_color colors)
{
	if (dot == NULL)
		puterror("Error: dot is NULL");
	dot->is_paint = 1;
	dot->color = colors.botco;
	if (dot->hexa_color > 0)
	{
		dot->color = dot->hexa_color;
		return ;
	}
	if (dot->ax[2] == max_h)
		dot->color = colors.topco;
	else if (dot->ax[2] == 0)
		dot->color = colors.groundco;
	else if (dot->ax[2] == min_h && min_h != 0)
		dot->color = colors.botco;
	else if (dot->ax[2] > 0)
		dot->color = interpolate_color(colors.groundco,
				colors.topco, max_h, dot->ax[2]);
	else
		dot->color = interpolate_color(colors.botco, colors.groundco,
				-min_h, -(min_h - dot->ax[2]));
}

int	parse_hexaco(char *line)
{
	int		color_value;
	char	**color_parts;

	if (ft_strchr(line, ',') != 0)
	{
		color_parts = ft_split(line, ',');
		if (!color_parts)
			return (0);
		if (color_parts[1] != NULL)
			color_value = ft_htoi(color_parts[1]);
		else
			color_value = 0;
		free_double_pointer((void **)color_parts);
		return (color_value);
	}
	return (0);
}

int	is_valid_point(char *value)
{
	int	valid;

	valid = 0;
	if (*value == '-' || *value == '+' || ft_isdigit(*value))
		valid++;
	value++;
	while (ft_isdigit(*value))
	{
		value++;
		valid++;
	}
	if (valid == 0)
		return (0);
	else
		return (1);
}

void	initialize_color(t_map *map)
{
	map->colors.backco = DARK;
	map->colors.botco = BOTTOM_COLOR;
	map->colors.topco = TOP_COLOR;
	map->colors.groundco = GROUND_COLOR;
}
