/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:15:12 by aparabos          #+#    #+#             */
/*   Updated: 2018/03/05 13:41:26 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_next_line(const int fd, char **line)
{
	int				size;
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	static char		*str = NULL;

	if (fd < 0 || line == NULL)
		return (-1);
	if (str == NULL)
		str = ft_strnew(1);
	while (!ft_strchr(str, '\n') && (size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		tmp = ft_strdup(str);
		buffer[size] = '\0';
		if (str)
			ft_strdel(&str);
		str = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	if (size == -1)
		return (-1);
	*line = (ft_strchr(str, '\n') ? ft_strsub(str, 0,
				ft_strchr(str, '\n') - str) : ft_strdup(str));
	ft_strchr(str, '\n') ? str = ft_strsubdel(str,
			ft_strchr(str, '\n') - str + 1, ft_strlen(str)) : ft_strdel(&str);
	return (!str && ft_strlen(*line) == 0 ? 0 : 1);
}
