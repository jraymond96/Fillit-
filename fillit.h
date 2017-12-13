/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraymond <jraymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:11:32 by jraymond          #+#    #+#             */
/*   Updated: 2017/12/09 17:35:29 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define SIZE_MINOS 21
# define MAX_TETRIMINOS 26
# define MAX_BUFFER (MAX_TETRIMINOS * SIZE_MINOS)

typedef struct			s_list_minos
{
	int					*coord;
	char				letter;
	struct s_list_minos	*next;
}						t_list_minos;

void					ft_error(int i);
void					ft_fillit(char *argv);
char					**ft_creat_tab_minos(int fd, int *j);
void					ft_valid_input(char **tab);
t_list_minos			*ft_creat_lst_with_coord_of_minos(char **tab);
int						*ft_creat_tab_coord_minos(char *buff);
t_list_minos			*ft_lst_creat_elem(int letter);
void					ft_fill_lst_coord(t_list_minos *begin_list, int letter,
							int *coord_minos);
void					ft_free_map(char **tab);
char					**ft_solve(t_list_minos *begin_list, int nb_minos);
int						ft_size_map(int nb_minos);
char					**ft_creat_map(int size_map);
int						*ft_adapt_coord_with_pos(t_list_minos *list,
							int size_map, int pos);
int						check_coord_if_out_map(int *coord, int size_map);
int						ft_check_minos_can_placed(int *coord, char **map,
							int size_map);
void					ft_put_minos(char **map, int *coord,
							t_list_minos *list);
int						ft_backtrack(t_list_minos *list, char **map,
							int size_map);
void					ft_erase_map_letter(char **map, char c);
void					ft_print_map(char **map);
void					ft_free_list(t_list_minos *elem);

#endif
