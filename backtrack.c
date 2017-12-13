/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:38:07 by jraymond          #+#    #+#             */
/*   Updated: 2017/12/08 17:05:18 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_backtrack(t_list_minos *list, char **map, int size_map)
{
	int	pos;
	int	*coord;

	if (list == NULL)
		return (1);
	pos = 0;
	while (pos < size_map * size_map)
	{
		coord = ft_adapt_coord_with_pos(list, size_map, pos);
		if (ft_check_minos_can_placed(coord, map, size_map) == 0)
		{
			ft_put_minos(map, coord, list);
			if (ft_backtrack(list->next, map, size_map) == 1)
			{
				free(coord);
				return (1);
			}
		}
		ft_erase_map_letter(map, list->letter);
		pos++;
	}
	return (-1);
}
