/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:19:59 by jraymond          #+#    #+#             */
/*   Updated: 2017/12/08 17:07:00 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list_minos	*ft_creat_lst_with_coord_of_minos(char **tab)
{
	char			buff[SIZE_MINOS + 1];
	t_list_minos	*begin_list;
	int				letter;
	int				*coord;

	letter = 0;
	ft_bzero(buff, SIZE_MINOS + 1);
	begin_list = ft_lst_creat_elem(letter);
	while (*tab)
	{
		coord = ft_creat_tab_coord_minos(*tab);
		ft_fill_lst_coord(begin_list, letter, coord);
		ft_bzero(buff, SIZE_MINOS + 1);
		letter++;
		tab++;
	}
	free(coord);
	return (begin_list);
}
