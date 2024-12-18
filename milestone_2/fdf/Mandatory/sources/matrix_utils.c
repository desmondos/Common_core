/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:31:56 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 12:08:24 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_dot	multiply_matrix(float mat[3][3], t_dot dot)
{
	int		row;
	int		col;
	t_dot	result;

	row = 0;
	result = dot;
	while (row < 3)
	{
		result.ax[row] = 0;
		col = 0;
		while (col < 3)
		{
			result.ax[row] += mat[row][col] * dot.ax[col];
			col++;
		}
		row++;
	}
	return (result);
}

void	ortho_projection(t_dot *dots, t_dot *proj, int length)
{
	int		pos;
	float	mat_rot[3][3];

	initialize_matrix(mat_rot);
	mat_rot[0][0] = 1;
	mat_rot[1][1] = 1;
	pos = 0;
	while (pos < length)
	{
		proj[pos] = multiply_matrix(mat_rot, dots[pos]);
		pos++;
	}
}

void	rotate_around_x(t_dot *dots, t_dot *proj, float angle, int length)
{
	int		pos;
	float	rad;
	float	mat_rot[3][3];

	rad = angle * M_PI / 180.0;
	initialize_matrix(mat_rot);
	mat_rot[0][0] = 1;
	mat_rot[1][1] = cos(rad);
	mat_rot[1][2] = -sin(rad);
	mat_rot[2][1] = sin(rad);
	mat_rot[2][2] = cos(rad);
	pos = 0;
	while (pos < length)
	{
		proj[pos] = multiply_matrix(mat_rot, dots[pos]);
		pos++;
	}
}

void	rotate_around_y(t_dot *dots, t_dot *proj, float angle, int length)
{
	int		pos;
	float	rad;
	float	mat_rot[3][3];

	rad = angle * M_PI / 180.0;
	initialize_matrix(mat_rot);
	mat_rot[0][0] = cos(rad);
	mat_rot[0][2] = sin(rad);
	mat_rot[1][1] = 1;
	mat_rot[2][0] = -sin(rad);
	mat_rot[2][2] = cos(rad);
	pos = 0;
	while (pos < length)
	{
		proj[pos] = multiply_matrix(mat_rot, dots[pos]);
		pos++;
	}
}

void	rotate_around_z(t_dot *dots, t_dot*proj, float angle, int length)
{
	int		pos;
	float	rad;
	float	mat_rot[3][3];

	rad = angle * M_PI / 180.0;
	initialize_matrix(mat_rot);
	mat_rot[0][0] = cos(rad);
	mat_rot[0][1] = -sin(rad);
	mat_rot[1][0] = sin(rad);
	mat_rot[1][1] = cos(rad);
	mat_rot[2][2] = 1;
	pos = 0;
	while (pos < length)
	{
		proj[pos] = multiply_matrix(mat_rot, dots[pos]);
		pos++;
	}
}
