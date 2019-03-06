/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:16:24 by lduqueno          #+#    #+#             */
/*   Updated: 2019/03/04 18:33:35 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			scale_view(t_mlx **data)
{
	if ((*data)->proj == 0)
	{
		(*data)->spacing = (((*data)->win_y - 225)) / (*data)->ymax;
		(*data)->pix_x = (*data)->win_x / 2
			- ((*data)->spacing * (*data)->xmax / 2);
		(*data)->pix_y = ((*data)->win_y - 225) / 2
			- ((*data)->spacing * (*data)->ymax / 2);
	}
	else
	{
		(*data)->spacing = (((*data)->win_y - 225)) / ((*data)->ymax * 2);
		(*data)->pix_x = (*data)->win_x / 2
			- ((*data)->spacing * (*data)->xmax / 4);
	}
	(*data)->depth = 1;
	(*data)->theta_x = 0.0;
	(*data)->theta_y = 0.0;
	(*data)->theta_z = 0.0;
}

void			coord_init(t_mlx **data, int i, t_point **point)
{
	int	j;
	int	spacing;

	j = -1;
	spacing = (*data)->spacing;
	while (++j < (*data)->xmax)
	{
		point[i][j].raw_z = (*data)->map[i][j];
		point[i][j].z = (*data)->map[i][j] * (*data)->depth;
		if ((*data)->proj == 1)
		{
			point[i][j].x = ((j - i) * spacing - point[i][j].z);
			point[i][j].y = ((i + j) * spacing / 2 - point[i][j].z);
		}
		else
		{
			point[i][j].x = (j * spacing - point[i][j].z);
			point[i][j].y = (i * spacing - point[i][j].z);
		}
		handle_rotate(data, &point[i][j]);
		point[i][j].x += (*data)->pix_x;
		point[i][j].y += (*data)->pix_y;
	}
}
