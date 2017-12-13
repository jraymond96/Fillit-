/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_coord_with_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:26:01 by jraymond          #+#    #+#             */
/*   Updated: 2017/12/09 17:24:56 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*ft_adapt_coord_with_pos(t_list_minos *list, int size_map, int pos)
{
	int	*coord;
	int	*tmp;
	int	x;

	((coord = (int*)malloc(sizeof(int) * 9)) == NULL ? ft_error(-1) : NULL);
	tmp = coord;
	x = 0;
	coord[8] = 42;
	while (list->coord[x] != 42)
	{
		coord[x] = list->coord[x] + (pos % size_map);
		coord[x + 1] = list->coord[x + 1] + (pos / size_map);
		x = x + 2;
	}
	return (tmp);
}

int	check_coord_if_out_map(int *coord, int size_map)
{
	while (*coord != 42)
	{
		if (*coord >= size_map)
			return (-1);
		coord++;
	}
	return (0);
}

int	ft_check_minos_can_placed(int *coord, char **map, int size_map)
{
	int	x;

	x = 0;
	if (check_coord_if_out_map(coord, size_map) == -1)
		return (-1);
	while (x <= 6)
	{
		if (map[coord[x + 1]][coord[x]] != '.')
			return (-1);
		x = x + 2;
	}
	return (0);
}
