/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <jauplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:07:19 by jauplat           #+#    #+#             */
/*   Updated: 2017/12/09 17:26:52 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free_map(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		free(tab[y]);
		tab[y] = NULL;
		y++;
	}
	free(tab);
	tab = NULL;
}

void		ft_free_list(t_list_minos *elem)
{
	t_list_minos	*tmp;

	while (elem)
	{
		free(elem->coord);
		tmp = elem->next;
		free(elem);
		elem = tmp;
	}
}
