/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:05:01 by lduqueno          #+#    #+#             */
/*   Updated: 2019/03/04 15:14:01 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_help(void)
{
	ft_printf("-------------- FdF --------------\n\n");
	ft_printf("Deplacement : [W] [A] [S] [D]\n");
	ft_printf("Rotation : [FLECHES] [<] [>]\n");
	ft_printf("Zoom : [+] [-]\n");
	ft_printf("Profondeur : [PAD_+] [PAD_-] \n");
	ft_printf("Projection : [P]\n");
	ft_printf("Reinitialisation : [R]\n");
	ft_printf("Quitter [ESC]\n\n");
}
