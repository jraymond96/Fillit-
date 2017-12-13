/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_tab_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:52:42 by jraymond          #+#    #+#             */
/*   Updated: 2017/12/08 17:08:04 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_origin_00(int *coord_minos)
{
	int	x_ori;
	int	y_ori;

	x_ori = *coord_minos;
	y_ori = *(coord_minos + 1);
	while (*coord_minos != 42)
	{
		*coord_minos = *coord_minos - x_ori;
		coord_minos++;
		*coord_minos = *coord_minos - y_ori;
		coord_minos++;
	}
}

static int		*ft_put_coord_in_tab(char buff, int *x, int *y, int *coord)
{
	if (buff == '#')
	{
		*coord = *x;
		coord++;
		*coord = *y;
		coord++;
		*x = *x + 1;
		return (coord);
	}
	if (buff == '\n')
	{
		*y = *y + 1;
		*x = -1;
	}
	*x = *x + 1;
	return (coord);
}

int				*ft_creat_tab_coord_minos(char *buff)
{
	int	*coord;
	int	*bis_coord;
	int	x;
	int	y;
	int	counter;

	if (!(coord = (int*)malloc(sizeof(int) * 9)))
		ft_error(1);
	bis_coord = coord;
	x = 0;
	y = 0;
	counter = 0;
	while (*buff)
	{
		bis_coord = ft_put_coord_in_tab(*buff, &x, &y, bis_coord);
		buff++;
	}
	*bis_coord = 42;
	ft_origin_00(coord);
	return (coord);
}
