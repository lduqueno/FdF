/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:25:09 by ccharrie          #+#    #+#             */
/*   Updated: 2019/03/04 15:26:11 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		zoom_input(t_mlx **data, int keycode)
{
	int		df_x;
	int		df_y;
	int		ospc;

	ospc = (*data)->spacing;
	if (keycode == KEY_EQUAL)
	{
		(*data)->spacing++;
		df_x = abs(ospc * (*data)->xmax - (*data)->spacing * (*data)->xmax);
		df_y = abs(ospc * (*data)->ymax - (*data)->spacing * (*data)->ymax);
		(*data)->pix_x -= df_x / 2;
		(*data)->pix_y -= df_y / 2;
	}
	if (keycode == KEY_MINUS && (*data)->spacing - 1 > 2)
	{
		(*data)->spacing--;
		df_x = abs(ospc * (*data)->xmax - (*data)->spacing * (*data)->xmax);
		df_y = abs(ospc * (*data)->ymax - (*data)->spacing * (*data)->ymax);
		(*data)->pix_x += df_x / 2;
		(*data)->pix_y += df_y / 2;
	}
}

static void		rotate_input(t_mlx **data, int keycode)
{
	if (keycode == KEY_RIGHT)
		(*data)->theta_y += 0.1;
	if (keycode == KEY_LEFT)
		(*data)->theta_y -= 0.1;
	if (keycode == KEY_UP)
		(*data)->theta_x += 0.1;
	if (keycode == KEY_DOWN)
		(*data)->theta_x -= 0.1;
	if (keycode == KEY_COMMA)
		(*data)->theta_z -= 0.1;
	if (keycode == KEY_DOT)
		(*data)->theta_z += 0.1;
}

static void		move_input(t_mlx **data, int keycode)
{
	if (keycode == KEY_D)
		(*data)->pix_x += 10;
	if (keycode == KEY_A)
		(*data)->pix_x -= 10;
	if (keycode == KEY_W)
		(*data)->pix_y -= 10;
	if (keycode == KEY_S)
		(*data)->pix_y += 10;
}

static void		proj_input(t_mlx **data)
{
	if ((*data)->proj == 0)
	{
		(*data)->proj = 1;
		(*data)->spacing = (((*data)->win_y - 225)) / ((*data)->ymax * 2);
		(*data)->pix_x = (*data)->win_x / 2
			- ((*data)->spacing * (*data)->xmax / 4);
		(*data)->pix_y += (*data)->win_y / 10;
	}
	else
	{
		(*data)->proj = 0;
		(*data)->pix_y -= (*data)->win_y / 10;
		(*data)->spacing = (((*data)->win_y - 225)) / (*data)->ymax;
		(*data)->pix_x = (*data)->win_x / 2
			- ((*data)->spacing * (*data)->xmax / 2);
	}
}

int				keyboard_input(int key, t_mlx **data)
{
	if (key == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (key == KEY_EQUAL || key == KEY_MINUS)
		zoom_input(data, key);
	if (key == KEY_RIGHT || key == KEY_LEFT || key == KEY_UP || key == KEY_DOWN
			|| key == KEY_COMMA || key == KEY_DOT)
		rotate_input(data, key);
	if (key == KEY_D || key == KEY_A || key == KEY_W || key == KEY_S)
		move_input(data, key);
	if (key == KEY_R)
		scale_view(data);
	if (key == KEY_P)
		proj_input(data);
	if (key == KEY_PAD_ADD && ((*data)->depth - 2) < 30)
		(*data)->depth += 2;
	if (key == KEY_PAD_SUB && ((*data)->depth - 2) >= 1)
		(*data)->depth -= 2;
	screen_reset(data);
	return (0);
}
