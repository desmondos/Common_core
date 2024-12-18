/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:02 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 12:27:41 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_press(int keycode, t_fdf *fdf)
{
	handle_angle_control(keycode, fdf);
	handle_tools_one(keycode, fdf);
	return (0);
}

int	key_release(int keycode, t_fdf *fdf)
{
	if (keycode == CTRL_R || keycode == CTRL_L)
	{
		fdf->key.leftctrl = 0;
		fdf->key.rightctrl = 0;
	}
	return (0);
}

void	handle_tools_one(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		exit_program(fdf);
}
