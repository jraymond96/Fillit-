# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jauplat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 15:53:07 by jauplat           #+#    #+#              #
#    Updated: 2017/12/09 17:42:22 by jauplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

PLIB = ./libft\

LIB = ./libft/libft.a

SRC = 	adapt_coord_with_pos.c backtrack.c creat_list.c creat_tab_coord.c \
		creat_tab_minos.c erase_map_letter.c error.c fill_list.c fillit.c \
		ft_creat_map.c ft_free_map.c ft_put_minos.c ft_size_map.c \
		ft_valid_input.c main.c print_map.c solve.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@(cd $(PLIB) && make)
		$(CC) $(FLAGS) $(LIB) $(SRC) -o $(NAME)

%.o : %.c
		$(CC) $(FLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJ)
		cd $(PLIB) && make clean

fclean: clean
		rm -rf $(NAME)
		@(cd $(PLIB) && make fclean)

re: fclean all

.PHONY: all clean fclean re
