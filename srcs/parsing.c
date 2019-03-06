/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 04:47:01 by ccharrie          #+#    #+#             */
/*   Updated: 2019/03/04 19:18:51 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static int		get_map(char **split, t_mlx **data, int i)
{
	int		j;

	j = -1;
	if (!((*data)->map[i] = (int *)malloc(sizeof(int) * (*data)->xmax)))
		return (assert_error("FdF map[i] malloc "));
	while (split[++j])
		(*data)->map[i][j] = ft_atoi(split[j]);
	j = -1;
	while (split[++j])
		ft_strdel(&split[j]);
	return (0);
}

static int		check_map(t_mlx **data, char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	(*data)->xmax = -1;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if ((split = ft_strsplit(line, ' ')) == NULL)
			return (assert_error("FdF split lines "));
		if ((*data)->xmax == -1)
			(*data)->xmax = ft_tablen(split);
		else if (ft_tablen(split) != (*data)->xmax || ft_tablen(split) < 1)
			return (assert_error("FdF bad map "));
		if ((*data)->xmax == 0)
			return (assert_error("FdF empty map "));
		if (get_map(split, data, i++) == -1)
			return (-1);
		free(split);
		ft_strdel(&line);
	}
	return (0);
}

int				to_parser(char *file, t_mlx **data)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (assert_error("FdF open "));
	(*data)->ymax = 0;
	while (get_next_line(fd, &line) > 0)
	{
		(*data)->ymax++;
		ft_strdel(&line);
	}
	if ((*data)->ymax == 0)
		return (assert_error("FdF empty map "));
	if (!((*data)->map = (int **)malloc(sizeof(int *) * (*data)->ymax)))
		return (assert_error("FdF malloc map "));
	close(fd);
	if (check_map(data, file) == -1)
		return (-1);
	return (0);
}
