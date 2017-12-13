/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_tab_minos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <jauplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:02:27 by jauplat           #+#    #+#             */
/*   Updated: 2017/12/08 17:09:15 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_creat_tab_minos(int fd, int *j)
{
	char	buff[MAX_BUFFER];
	int		r;
	int		i;
	int		k;
	char	**tab;

	k = 0;
	r = read(fd, &buff, MAX_BUFFER);
	buff[r] = '\0';
	if (!(tab = (char **)malloc(sizeof(char *) * (MAX_TETRIMINOS + 1))))
		ft_error(-1);
	while (buff[k])
	{
		i = 0;
		if (!(tab[*j] = (char *)malloc(sizeof(char) * (SIZE_MINOS + 1))))
			ft_error(-1);
		while (i != SIZE_MINOS && buff[k])
			tab[*j][i++] = buff[k++];
		tab[*j][i] = '\0';
		(*j)++;
	}
	if ((r + 1) % SIZE_MINOS != 0)
		ft_error(-1);
	tab[*j] = NULL;
	return (tab);
}
