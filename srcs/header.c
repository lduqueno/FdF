/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:53:14 by ccharrie          #+#    #+#             */
/*   Updated: 2019/03/04 15:02:34 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		header_ui(t_mlx **data)
{
	int		i;

	i = -1;
	while (++i < (*data)->win_x)
		mlx_pixel_put((*data)->mlx_p, (*data)->win_p, i, 225, 0x525252);
	i = -1;
	while (++i < 225)
		mlx_pixel_put((*data)->mlx_p, (*data)->win_p, 225, i, 0x525252);
	mlx_string_put((*data)->mlx_p, (*data)->win_p, 25, 201, (*data)->img_cl,
		"change image color");
	mlx_string_put((*data)->mlx_p, (*data)->win_p, (*data)->win_x - 425, 5,
		(*data)->img_cl, "FdF made by ccharrie and lduqueno");
}

void			print_header(t_mlx **data)
{
	int		bpp;
	int		ed;
	int		sz;
	char	*tmp;

	if (((*data)->whe_p = mlx_xpm_file_to_image((*data)->mlx_p,
			"resources/color_wheel.xpm", &sz, &ed)) == NULL)
		assert_error("FdF color wheel ");
	tmp = mlx_get_data_addr((*data)->whe_p, &bpp, &sz, &ed);
	(*data)->whe_d = (unsigned int *)tmp;
	(*data)->szp = sz;
	mlx_put_image_to_window((*data)->mlx_p, (*data)->win_p, (*data)->whe_p,
		0, 0);
	if (((*data)->men_p = mlx_xpm_file_to_image((*data)->mlx_p,
			"resources/menu.xpm", &sz, &ed)) == NULL)
		assert_error("FdF menu xpm ");
	(*data)->men_w = sz;
	mlx_put_image_to_window((*data)->mlx_p, (*data)->win_p, (*data)->men_p,
		((*data)->win_x - (*data)->men_w) / 2, 5);
	header_ui(data);
}

int				release(int button, int x, int y, t_mlx **data)
{
	(void)button;
	if (x > 0 && y > 0)
	{
		(*data)->ispress = 0;
		if (x < 200 && y < 200 && x > 0 && y > 0)
			if ((*data)->whe_d[(y * (*data)->szp / 4) + x] != 4278190080)
			{
				(*data)->img_cl = (*data)->whe_d[(y * (*data)->szp / 4) + x];
				screen_reset(data);
			}
	}
	return (0);
}

int				press(int button, int x, int y, t_mlx **data)
{
	(void)button;
	if (x > 0 && y > 0)
		(*data)->ispress = 1;
	return (0);
}

int				mouse(int x, int y, t_mlx **data)
{
	if ((*data)->ispress == 1)
	{
		if (x < 200 && y < 200 && x > 0 && y > 0)
			if ((*data)->whe_d[(y * (*data)->szp / 4) + x] != 4278190080)
			{
				(*data)->img_cl = (*data)->whe_d[(y * (*data)->szp / 4) + x];
				screen_reset(data);
			}
	}
	return (0);
}
