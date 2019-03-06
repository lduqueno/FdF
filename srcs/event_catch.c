/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_catch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:34:53 by ccharrie          #+#    #+#             */
/*   Updated: 2019/03/04 15:32:08 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			clear_menu_win(t_mlx_data **data)
{
	mlx_clear_window((*data)->mlx_p, (*data)->win_p);
	mlx_put_image_to_window((*data)->mlx_p, (*data)->win_p, (*data)->men_p,
		((*data)->win_x - (*data)->men_w) / 2, 5);
	mlx_put_image_to_window((*data)->mlx_p, (*data)->win_p, (*data)->whe_p,
		0, 0);
	put_to_win(data);
}

static void		key_tabfunc(t_keyfunc *key_tab)
{
	key_tab[0].key = KEY_DOWN;
	key_tab[0].func = select_down;
	key_tab[1].key = KEY_UP;
	key_tab[1].func = select_up;
	key_tab[2].key = KEY_RIGHT;
	key_tab[2].func = select_right;
	key_tab[3].key = KEY_LEFT;
	key_tab[3].func = select_left;
	key_tab[4].key = KEY_ESCAPE;
	key_tab[4].func = key_exit;
	key_tab[5].key = KEY_ENTER;
	key_tab[5].func = key_enter;
}

int				get_event(int key, t_mlx_data **data)
{
	t_keyfunc	key_tab[6];
	int			i;

	key_tabfunc(key_tab);
	i = -1;
	while (++i < 6)
		if (key_tab[i].key == key)
			key_tab[i].func(data);
	clear_menu_win(data);
	return (0);
}

int				mouse_press(int button, int x, int y, t_mlx_data **data)
{
	(void)button;
	if (x > 0 && y > 0)
		(*data)->ispress = 1;
	return (0);
}

int				mouse_event(int x, int y, t_mlx_data **data)
{
	if ((*data)->ispress == 1)
	{
		if (x < 200 && y < 200 && x > 0 && y > 0)
			if ((*data)->whe_d[(y * (*data)->szp / 4) + x] != 4278190080)
			{
				(*data)->txt_c = (*data)->whe_d[(y * (*data)->szp / 4) + x];
				clear_menu_win(data);
			}
	}
	return (0);
}
