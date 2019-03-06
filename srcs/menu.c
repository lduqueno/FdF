/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:24:16 by ccharrie          #+#    #+#             */
/*   Updated: 2019/03/04 19:21:28 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			menu_header(t_mlx_data **data)
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
}

void			ultimate_cursor(t_mlx_data **data)
{
	int		i;

	i = -1;
	if ((*data)->files)
	{
		mlx_string_put((*data)->mlx_p, (*data)->win_p, (*data)->cur_x,
			(*data)->cur_y, 0xFFFFFF, "->");
	}
	while (++i < (*data)->win_x)
		mlx_pixel_put((*data)->mlx_p, (*data)->win_p, i, 225, 0x525252);
	i = -1;
	while (++i < 225)
		mlx_pixel_put((*data)->mlx_p, (*data)->win_p, 225, i, 0x525252);
	draw_str_centered(*data, 112, 201, "change text color");
	mlx_string_put((*data)->mlx_p, (*data)->win_p, (*data)->win_x - 250, 5,
		(*data)->txt_c, "Menu made by ccharrie");
	mlx_string_put((*data)->mlx_p, (*data)->win_p, (*data)->win_x - 280, 25,
	(*data)->txt_c, "https://github.com/ccharrie");
	draw_str_centered(*data, (*data)->win_x / 2, 225, (*data)->men_m);
}

static void		draw_list(t_mlx_data **data, int x, int y, int i)
{
	if (!(*data)->files)
	{
		draw_str_centered(*data, (*data)->win_x / 2, 400, "No map found here");
		return ;
	}
	while ((*data)->files)
	{
		if (y > ((*data)->win_y - 50))
		{
			if ((*data)->txt_fpl < 0)
				(*data)->txt_fpl = i;
			y = 250;
			x += 250;
		}
		if ((*data)->men_mode == 0)
			mlx_string_put((*data)->mlx_p, (*data)->win_p, x, y, (*data)->txt_c,
				(*data)->files->cnt);
		else if ((*data)->men_mode == 1)
			draw_str_centered(*data, (*data)->win_x / 2, y,
				(*data)->files->cnt);
		y += 20;
		(*data)->files = (*data)->files->next;
		i++;
	}
}

int				mouse_release(int button, int x, int y, t_mlx_data **data)
{
	(void)button;
	if (x > 0 && y > 0)
	{
		(*data)->ispress = 0;
		{
			if (x < 200 && y < 200 && x > 0 && y > 0)
				if ((*data)->whe_d[(y * (*data)->szp / 4) + x] != 4278190080)
				{
					(*data)->txt_c = (*data)->whe_d[(y * (*data)->szp / 4) + x];
					clear_menu_win(data);
				}
		}
	}
	return (0);
}

void			put_to_win(t_mlx_data **data)
{
	t_dlist	*header;
	int		i;

	header = (*data)->files;
	i = 0;
	draw_list(data, (*data)->txt_x, (*data)->txt_y, i);
	(*data)->files = header;
	if ((*data)->men_f)
		draw_str_centered(*data, (*data)->win_x / 2, 245, (*data)->men_f);
	ultimate_cursor(data);
	mlx_hook((*data)->win_p, 2, 3, get_event, data);
	mlx_hook((*data)->win_p, 4, 4, mouse_press, data);
	mlx_hook((*data)->win_p, 5, 8, mouse_release, data);
	mlx_hook((*data)->win_p, 6, 8192, mouse_event, data);
	mlx_loop((*data)->mlx_p);
}
