/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <jauplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:36:34 by jauplat           #+#    #+#             */
/*   Updated: 2017/12/08 17:11:54 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_creat_map(int size_map)
{
	int		x;
	int		y;
	char	**map;

	map = NULL;
	y = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size_map + 1))))
		ft_error(-1);
	while (y < size_map)
	{
		x = 0;
		if (!(map[y] = (char *)malloc(sizeof(char) * (size_map + 1))))
			ft_error(-1);
		while (x < size_map)
			map[y][x++] = '.';
		map[y][x] = '\0';
		y++;
	}
	map[y] = NULL;
	return (map);
}
