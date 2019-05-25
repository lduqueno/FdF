/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:26:06 by ccharrie          #+#    #+#             */
/*   Updated: 2019/05/25 19:23:37 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_is_folder(const char *path)
{
	struct stat buf;

	stat(path, &buf);
	if (S_ISDIR(buf.st_mode))
		return (1);
	if (S_ISREG(buf.st_mode))
		return (0);
	return (assert_error("FdF file "));
}

void			push_list(t_dlist **lst, char *name)
{
	t_dlist	*new;

	if (!(new = (t_dlist *)malloc(sizeof(t_dlist))))
		return ;
	new->cnt = ft_strdup(name);
	new->next = NULL;
	new->prev = NULL;
	ft_dlstpushback(lst, new);
}

static void		get_files(t_mlx_data **data)
{
	struct dirent	**folder;
	int				i;
	int				len;

	folder = NULL;
	(*data)->files = NULL;
	i = -1;
	len = scandir((*data)->path, &folder, NULL, alphasort);
	while (++i < len)
		if (folder[i]->d_type == DT_REG && ft_strstr(folder[i]->d_name, ".fdf"))
			push_list(&(*data)->files, folder[i]->d_name);
	while (len--)
		free(folder[len]);
	free(folder);
}

static int		menu_init(t_mlx_data **data)
{
	(*data)->cur_x = 25;
	(*data)->cur_y = 250;
	(*data)->txt_c = 0xFFFFFF;
	(*data)->txt_fpl = -1;
	(*data)->txt_y = 250;
	(*data)->txt_x = 50;
	(*data)->men_mode = 0;
	(*data)->ispress = 0;
	(*data)->men_f = NULL;
	(*data)->men_m = ft_strdup("Choose a map");
	get_files(data);
	(*data)->cur_file = (*data)->files;
	menu_header(data);
	put_to_win(data);
	return (1);
}

int				main(int ac, char **av)
{
	t_mlx_data	*data;

	if (ac != 2)
	{
		ft_putendl("fdf usage : ./fdf [file | folder]");
		return (0);
	}
	if (!(data = (t_mlx_data *)malloc(sizeof(t_mlx_data))))
		return (assert_error("FdF malloc data "));
	if (!(data->mlx_p = mlx_init()))
		return (assert_error("Fdf mlx_init "));
	data->path = ft_strdup(av[1]);
	data->win_x = 1280;
	data->win_y = 720;
	data->win_p = mlx_new_window(data->mlx_p, data->win_x, data->win_y,
		data->path);
	print_help();
	if (check_is_folder(av[1]) == 1)
		menu_init(&data);
	else if (check_is_folder(av[1]) == 0)
		file_to_res(&data);
	return (0);
}
