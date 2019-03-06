/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:53:36 by lduqueno          #+#    #+#             */
/*   Updated: 2019/03/04 14:57:26 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rotation_x(t_mlx *mlx, int *y, int *z)
{
	int	new_z;
	int new_y;

	new_y = ((cos(mlx->theta_x) * *y) + (-sin(mlx->theta_x) * *z));
	new_z = ((sin(mlx->theta_x) * *y) + (cos(mlx->theta_x) * *z));
	*y = new_y;
	*z = new_z;
}

static void		rotation_y(t_mlx *mlx, int *x, int *z)
{
	int	new_z;
	int new_x;

	new_x = ((cos(mlx->theta_y) * *x) + (sin(mlx->theta_y) * *z));
	new_z = ((-sin(mlx->theta_y) * *x) + (cos(mlx->theta_y) * *z));
	*x = new_x;
	*z = new_z;
}

static void		rotation_z(t_mlx *mlx, int *x, int *y)
{
	int new_x;
	int new_y;

	new_x = ((sin(mlx->theta_z) * *y) + (cos(mlx->theta_z) * *x));
	new_y = ((cos(mlx->theta_z) * *y) + (-sin(mlx->theta_z) * *x));
	*x = new_x;
	*y = new_y;
}

void			handle_rotate(t_mlx **data, t_point *pnt)
{
	if ((*data)->proj == 1)
	{
		pnt->y -= (*data)->ymax * (*data)->spacing / 2;
		pnt->x -= (*data)->xmax * (*data)->spacing / 4;
	}
	else
	{
		pnt->y -= (*data)->ymax * (*data)->spacing / 2;
		pnt->x -= (*data)->xmax * (*data)->spacing / 2;
	}
	rotation_x(*data, &pnt->y, &pnt->z);
	rotation_y(*data, &pnt->x, &pnt->z);
	rotation_z(*data, &pnt->x, &pnt->y);
	if ((*data)->proj == 1)
	{
		pnt->y += (*data)->ymax * (*data)->spacing / 2;
		pnt->x += (*data)->xmax * (*data)->spacing / 4;
	}
	else
	{
		pnt->y += (*data)->ymax * (*data)->spacing / 2;
		pnt->x += (*data)->xmax * (*data)->spacing / 2;
	}
}
