/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_map_letter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:58:06 by jraymond          #+#    #+#             */
/*   Updated: 2017/12/08 17:10:21 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_erase_map_letter(char **map, char c)
{
	int	x;

	while (*map)
	{
		x = 0;
		while ((*map)[x])
		{
			if ((*map)[x] == c)
				(*map)[x] = '.';
			x++;
		}
		map++;
	}
}
