/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:08:09 by jraymond          #+#    #+#             */
/*   Updated: 2017/12/08 17:11:40 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list_minos	*ft_lst_creat_elem(int letter)
{
	t_list_minos	*new;

	if (!(new = (t_list_minos*)malloc(sizeof(t_list_minos))))
		ft_error(1);
	new->letter = 'A' + letter;
	if (!(new->coord = (int*)malloc(sizeof(int) * 9)))
		ft_error(1);
	new->next = NULL;
	return (new);
}

static void		ft_lst_add_elem_back(t_list_minos *begin_list, int letter)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	begin_list->next = ft_lst_creat_elem(letter);
}

static void		ft_memmove_tab(int *dest, int *src)
{
	int			x;

	x = 0;
	while (*src != 42)
	{
		dest++;
		src++;
		x++;
	}
	while (x != 0)
	{
		*dest = *src;
		dest--;
		src--;
		x--;
	}
}

void			ft_fill_lst_coord(t_list_minos *begin_list, int letter, \
		int *coord_minos)
{
	if (letter == 0)
	{
		ft_memmove_tab(begin_list->coord, coord_minos);
	}
	else
	{
		ft_lst_add_elem_back(begin_list, letter);
		while (begin_list->next)
		{
			begin_list = begin_list->next;
		}
		ft_memmove_tab(begin_list->coord, coord_minos);
	}
}
