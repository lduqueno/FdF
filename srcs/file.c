/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 01:30:51 by ccharrie          #+#    #+#             */
/*   Updated: 2019/03/04 16:19:55 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				assert_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
	return (-1);
}

void			draw_str_centered(t_mlx_data *mlx, int x, int y, char *s)
{
	size_t		len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (len == 0)
		return ;
	mlx_string_put(mlx->mlx_p, mlx->win_p, x - len * 10 / 2, y, mlx->txt_c, s);
}

static int		get_menu_data(t_mlx **f_data, t_mlx_data **data, char *res)
{
	char		**res_split;
	int			i;

	if (!(res_split = ft_strsplit(res, ' ')))
		return (assert_error("FdF strsplit "));
	(*f_data)->win_x = ft_atoi(res_split[0]);
	(*f_data)->win_y = ft_atoi(res_split[2]);
	i = -1;
	while (res_split[++i])
		ft_strdel(&res_split[i]);
	free(res_split);
	(*f_data)->mlx_p = (*data)->mlx_p;
	(*f_data)->img_cl = (*data)->txt_c;
	(*f_data)->ispress = 0;
	free(*data);
	return (0);
}

static int		to_image(t_mlx **data)
{
	int			avoid;

	(*data)->img_p = mlx_new_image((*data)->mlx_p, (*data)->win_x,
		(*data)->win_y - 225);
	(*data)->img_d = (unsigned int *)mlx_get_data_addr((*data)->img_p,
		&avoid, &avoid, &avoid);
	retrieve_most_occurence(data);
	if (!draw_init(data))
		return (-1);
	mlx_put_image_to_window((*data)->mlx_p, (*data)->win_p, (*data)->img_p, 0,
		226);
	return (1);
}

int				to_file(char *file, t_mlx_data **data, char *res)
{
	t_mlx		*f_data;

	if (!(f_data = (t_mlx *)malloc(sizeof(t_mlx))))
		return (assert_error("FdF malloc f_data "));
	if (get_menu_data(&f_data, data, res) == -1)
		return (-1);
	if (to_parser(file, &f_data) == -1)
		return (-1);
	f_data->win_p = mlx_new_window(f_data->mlx_p, f_data->win_x, f_data->win_y,
		file);
	f_data->proj = 0;
	scale_view(&f_data);
	print_header(&f_data);
	if (to_image(&f_data) == -1)
		return (assert_error("FdF to_image "));
	mlx_hook(f_data->win_p, 4, 4, press, &f_data);
	mlx_hook(f_data->win_p, 5, 8, release, &f_data);
	mlx_hook(f_data->win_p, 6, 8192, mouse, &f_data);
	mlx_hook(f_data->win_p, 2, 3, keyboard_input, &f_data);
	mlx_loop(f_data->mlx_p);
	return (0);
}
