/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:55:05 by jraymond          #+#    #+#             */
/*   Updated: 2017/12/08 17:12:56 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_solve(t_list_minos *begin_list, int nb_minos)
{
	char	**map;
	int		size_map;
	int		*coord;
	int		pos;

	pos = 0;
	size_map = ft_size_map(nb_minos);
	map = ft_creat_map(size_map);
	coord = ft_adapt_coord_with_pos(begin_list, size_map, pos);
	while (ft_backtrack(begin_list, map, size_map) == -1)
	{
		size_map++;
		ft_free_map(map);
		map = ft_creat_map(size_map);
	}
	return (map);
}
