/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:45:46 by lduqueno          #+#    #+#             */
/*   Updated: 2019/03/04 17:56:09 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			draw_horizontal(t_mlx **data, t_point point)
{
	int	cumul;
	int	i;
	int	x;
	int	y;

	cumul = point.dx / 2;
	i = 0;
	x = point.x;
	y = point.y;
	while (++i <= point.dx)
	{
		x += point.xinc;
		cumul += point.dy;
		if (cumul >= point.dx)
		{
			cumul -= point.dx;
			y += point.yinc;
		}
		if (y < (*data)->win_y - 225 && x < (*data)->win_x && x >= 0 && y >= 0)
			(*data)->img_d[y * (*data)->win_x + x] =
				get_color(data, point.raw_z);
	}
}

static void			draw_vertical(t_mlx **data, t_point point)
{
	int	cumul;
	int	i;
	int	x;
	int	y;

	cumul = point.dy / 2;
	i = 0;
	x = point.x;
	y = point.y;
	while (++i <= point.dy)
	{
		y += point.yinc;
		cumul += point.dx;
		if (cumul >= point.dy)
		{
			cumul -= point.dy;
			x += point.xinc;
		}
		if (y < (*data)->win_y - 225 && x < (*data)->win_x && x >= 0 && y >= 0)
			(*data)->img_d[y * (*data)->win_x + x] =
				get_color(data, point.raw_z);
	}
}

static void			draw_line(t_mlx **data, t_point *a, t_point *b)
{
	a->dx = b->x - a->x;
	a->dy = b->y - a->y;
	a->xinc = (a->dx > 0) ? 1 : -1;
	a->yinc = (a->dy > 0) ? 1 : -1;
	a->dx = abs(a->dx);
	a->dy = abs(a->dy);
	if (a->dx > a->dy)
		draw_horizontal(data, *a);
	else
		draw_vertical(data, *a);
}

static void			draw(t_mlx **data, t_point **point)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*data)->ymax)
	{
		j = -1;
		while (++j < (*data)->xmax)
		{
			if (point[i][j].y < ((*data)->win_y - 225) && point[i][j].x
				< (*data)->win_x && point[i][j].x >= 0 && point[i][j].y >= 0)
			{
				(*data)->img_d[point[i][j].y * (*data)->win_x + point[i][j].x] =
					get_color(data, point[i][j].raw_z);
			}
			if (j + 1 < (*data)->xmax)
				draw_line(data, &point[i][j], &point[i][j + 1]);
			if (i + 1 < (*data)->ymax)
				draw_line(data, &point[i][j], &point[i + 1][j]);
		}
	}
}

int					draw_init(t_mlx **data)
{
	t_point	**point;
	int		i;

	i = -1;
	if (!(point = (t_point **)malloc(sizeof(t_point *) * (*data)->ymax)))
		return (assert_error("FdF malloc point "));
	while (++i < (*data)->ymax)
	{
		if (!(point[i] = (t_point *)malloc(sizeof(t_point) * (*data)->xmax)))
			return (assert_error("FdF malloc point[i] "));
		coord_init(data, i, point);
	}
	draw(data, point);
	i = -1;
	while (++i < (*data)->ymax)
		free(point[i]);
	free(point);
	return (1);
}
