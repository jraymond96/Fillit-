/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <jauplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:20:14 by jauplat           #+#    #+#             */
/*   Updated: 2017/12/09 17:06:05 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_fillit(char *argv)
{
	t_list_minos	*begin_list;
	char			**tab;
	int				fd;
	int				nb_minos;

	nb_minos = 0;
	((fd = open(argv, O_RDONLY)) == -1 ? ft_error(-1) : NULL);
	tab = ft_creat_tab_minos(fd, &nb_minos);
	ft_valid_input(tab);
	begin_list = ft_creat_lst_with_coord_of_minos(tab);
	ft_free_map(tab);
	tab = ft_solve(begin_list, nb_minos);
	ft_free_list(begin_list);
	ft_print_map(tab);
	ft_free_map(tab);
}
