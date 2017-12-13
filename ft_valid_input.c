/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <jauplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:13:03 by jauplat           #+#    #+#             */
/*   Updated: 2017/12/08 17:12:30 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**-ft_check_nb_sharp will check a good number of character '#'
**-ft_check_point will check if all character are a '.', '#' or '\n'
**-ft_checkline_minos will check if we have a right number of character and line
**-ft_check_all permettly call another functions and take character chain in fd
*/

#include "fillit.h"

static int		ft_check_nb_sharp(char *buff, int i)
{
	int		count_minos;

	count_minos = 0;
	if (buff[i + 1] == '#')
		count_minos++;
	if (buff[i + 5] == '#')
		count_minos++;
	if (buff[i - 5] == '#')
		count_minos++;
	if (buff[i - 1] == '#')
		count_minos++;
	return (count_minos);
}

static int		ft_check_point(char *buff)
{
	int		i;
	int		count_minos;
	int		j;

	count_minos = 0;
	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
			return (0);
		if (buff[i] == '#')
		{
			count_minos += ft_check_nb_sharp(buff, i);
			j++;
		}
		i++;
	}
	if ((count_minos != 6 && count_minos != 8) || j != 4)
		return (0);
	return (1);
}

static int		ft_checkline_minos(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i + j])
	{
		while (buff[i + j] != '\n')
			i++;
		if (i % 4 != 0)
			return (0);
		j++;
	}
	return (1);
}

void			ft_valid_input(char **tab)
{
	int		y;

	y = 0;
	while (tab[y])
	{
		if (ft_checkline_minos(tab[y]) != 1 || ft_check_point(tab[y]) != 1)
			ft_error(-1);
		y++;
	}
}
