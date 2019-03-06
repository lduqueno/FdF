/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:27:27 by ccharrie          #+#    #+#             */
/*   Updated: 2019/01/22 16:43:35 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		select_down(t_mlx_data **data)
{
	if ((*data)->files && (*data)->cur_file->next)
	{
		if ((*data)->cur_y > (*data)->win_y - 70)
		{
			(*data)->cur_y = 250;
			(*data)->cur_x += 250;
		}
		else
			(*data)->cur_y += 20;
		(*data)->cur_file = (*data)->cur_file->next;
	}
}

void		select_up(t_mlx_data **data)
{
	if ((*data)->files && (*data)->cur_file->prev)
	{
		if ((*data)->cur_y < 270)
		{
			(*data)->cur_y = (*data)->win_y - 50;
			(*data)->cur_x -= 250;
		}
		else
			(*data)->cur_y -= 20;
		(*data)->cur_file = (*data)->cur_file->prev;
	}
}

void		select_left(t_mlx_data **data)
{
	int		i;

	i = -1;
	if ((*data)->files)
		while ((*data)->cur_file->prev && ++i < (*data)->txt_fpl)
			select_up(data);
}

void		select_right(t_mlx_data **data)
{
	int		i;

	i = -1;
	if ((*data)->files)
		while ((*data)->cur_file->next && ++i < (*data)->txt_fpl)
			select_down(data);
}

void		key_exit(t_mlx_data **mlx_data)
{
	(void)mlx_data;
	exit(0);
}
