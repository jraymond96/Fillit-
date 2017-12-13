/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_minos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <jauplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:20:09 by jauplat           #+#    #+#             */
/*   Updated: 2017/12/08 17:12:09 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_put_minos(char **map, int *coord, t_list_minos *list)
{
	int	y;
	int	x;
	int	k;

	k = 0;
	while (k < 7)
	{
		x = coord[k++];
		y = coord[k++];
		map[y][x] = list->letter;
	}
}
