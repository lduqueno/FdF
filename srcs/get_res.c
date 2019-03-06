/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:43:41 by ccharrie          #+#    #+#             */
/*   Updated: 2019/03/04 15:27:49 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			dlist_del(t_dlist **lst)
{
	if ((*lst)->next)
		dlist_del(&(*lst)->next);
	free((*lst)->cnt);
	free(*lst);
	*lst = NULL;
}

static void		to_file_parsing(t_mlx_data **data)
{
	ft_strdel(&(*data)->men_m);
	ft_strdel(&(*data)->men_f);
	mlx_destroy_window((*data)->mlx_p, (*data)->win_p);
	to_file((*data)->path, data, (*data)->cur_file->cnt);
}

static void		list_of_res(t_mlx_data **data)
{
	char	*resolution[6];
	int		i;

	i = -1;
	resolution[0] = "1024 x 576";
	resolution[1] = "1280 x 720";
	resolution[2] = "1440 x 810";
	resolution[3] = "1600 x 900";
	resolution[4] = "1920 x 1080";
	resolution[5] = "2048 x 1152";
	while (++i < 6)
		push_list(&(*data)->files, resolution[i]);
}

void			key_enter(t_mlx_data **data)
{
	if ((*data)->files)
	{
		if ((*data)->men_mode == 0)
		{
			(*data)->men_mode = 1;
			(*data)->men_f = ft_strdup((*data)->cur_file->cnt);
			(*data)->path = ft_strjoin_free((*data)->path, "/");
			(*data)->path = ft_strjoin_free((*data)->path,
				(*data)->cur_file->cnt);
			dlist_del(&(*data)->files);
			list_of_res(data);
			ft_strdel(&(*data)->men_m);
			(*data)->cur_file = (*data)->files;
			(*data)->men_m = ft_strdup("Choose a screen resolution");
			(*data)->cur_x = 550;
			(*data)->cur_y = 350;
			(*data)->txt_y = 350;
			clear_menu_win(data);
		}
		else
			to_file_parsing(data);
	}
}

int				file_to_res(t_mlx_data **data)
{
	if (!ft_strstr((*data)->path, ".fdf"))
	{
		ft_putendl("FdF : not a FdF map");
		return (-1);
	}
	(*data)->cur_x = 550;
	(*data)->cur_y = 350;
	(*data)->txt_x = 625;
	(*data)->txt_y = 350;
	(*data)->txt_c = 0xFFFFFF;
	(*data)->txt_fpl = -1;
	(*data)->men_mode = 1;
	(*data)->files = NULL;
	(*data)->men_f = ft_strdup((*data)->path);
	(*data)->men_m = ft_strdup("Choose a screen resolution");
	list_of_res(data);
	(*data)->cur_file = (*data)->files;
	menu_header(data);
	put_to_win(data);
	return (1);
}
