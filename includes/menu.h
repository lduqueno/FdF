/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:27:00 by ccharrie          #+#    #+#             */
/*   Updated: 2019/03/04 15:35:43 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

typedef struct		s_mlx_data
{
	t_dlist			*files;
	t_dlist			*cur_file;
	void			*mlx_p;
	void			*win_p;
	void			*men_p;
	char			*men_m;
	char			*men_f;
	int				men_mode;
	unsigned int	*whe_d;
	void			*whe_p;
	char			*path;
	int				win_x;
	int				win_y;
	int				cur_x;
	int				cur_y;
	int				txt_c;
	int				txt_fpl;
	int				txt_x;
	int				txt_y;
	int				szp;
	int				ispress;
	int				men_w;
}					t_mlx_data;

typedef struct		s_keyfunc
{
	int		key;
	void	(*func)(t_mlx_data **);
}					t_keyfunc;

void				put_to_win(t_mlx_data **data);
void				menu_header(t_mlx_data **mlx_data);
int					get_event(int key, t_mlx_data **data);
int					mouse_event(int x, int y, t_mlx_data **data);
void				key_exit(t_mlx_data **mlx_data);
void				select_right(t_mlx_data **data);
void				select_left(t_mlx_data **data);
void				select_up(t_mlx_data **data);
void				select_down(t_mlx_data **data);
void				key_enter(t_mlx_data **data);
void				push_list(t_dlist **lst, char *name);
void				clear_menu_win(t_mlx_data **data);
int					file_to_res(t_mlx_data **data);
int					mouse_press(int button, int x, int y, t_mlx_data **data);
int					mouse_release(int button, int x, int y, t_mlx_data **data);

#endif
