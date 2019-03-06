/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:32:20 by lduqueno          #+#    #+#             */
/*   Updated: 2019/03/04 15:33:17 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				screen_reset(t_mlx **data)
{
	int	i;

	i = -1;
	mlx_clear_window((*data)->mlx_p, (*data)->win_p);
	print_header(data);
	while (++i < (*data)->win_x * ((*data)->win_y - 225))
		(*data)->img_d[i] = 0x000000;
	if (!draw_init(data))
		return (-1);
	mlx_put_image_to_window((*data)->mlx_p, (*data)->win_p, (*data)->img_p, 0,
		226);
	return (0);
}
