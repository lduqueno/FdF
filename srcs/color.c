/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:57:45 by lduqueno          #+#    #+#             */
/*   Updated: 2019/03/04 18:41:55 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	assign_list(t_count **list, int z)
{
	if (!(*list = (t_count *)malloc(sizeof(t_count))))
		return (assert_error("FdF malloc t_count "));
	(*list)->next = NULL;
	(*list)->number = z;
	(*list)->count = 1;
	return (1);
}

static int	search_and_increment(t_count **list, int z)
{
	t_count	*begin_list;

	if (*list)
	{
		begin_list = *list;
		while (begin_list->next)
		{
			if (begin_list->number == z)
			{
				begin_list->count++;
				return (1);
			}
			begin_list = begin_list->next;
		}
		if (begin_list->number == z)
		{
			begin_list->count++;
			return (1);
		}
		assign_list(&begin_list->next, z);
	}
	else
		assign_list(list, z);
	return (1);
}

static void	find_coord_free(t_mlx **data, t_count **list)
{
	t_count	*tmp;
	int		max_occurence;

	(*data)->zmax = -2147483647;
	(*data)->zmin = 2147483647;
	max_occurence = 0;
	while (*list)
	{
		if ((*list)->number > (*data)->zmax)
			(*data)->zmax = (*list)->number;
		if ((*list)->number < (*data)->zmin)
			(*data)->zmin = (*list)->number;
		if ((*list)->count > max_occurence)
		{
			max_occurence = (*list)->count;
			(*data)->z_base = (*list)->number;
		}
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

void		retrieve_most_occurence(t_mlx **data)
{
	t_count	*list;
	int		i;
	int		j;

	list = NULL;
	i = -1;
	while (++i < (*data)->ymax)
	{
		j = -1;
		while (++j < (*data)->xmax)
			search_and_increment(&list, (*data)->map[i][j]);
	}
	find_coord_free(data, &list);
}

int			get_color(t_mlx **data, int z)
{
	int		color;

	color = (*data)->img_cl + (z - (*data)->z_base) * 20;
	if (color < 0x000000 + 250)
		return (0x000000 + 250);
	return (color);
}
