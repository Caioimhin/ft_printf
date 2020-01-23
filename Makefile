# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kparis <kparis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 11:21:04 by kparis            #+#    #+#              #
#    Updated: 2020/01/23 13:19:55 by kparis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_A = libft.a

LIBFT_H = -I libft/

LIB_DIR = libft/

SRC =	./ft_display_c.c \
		./ft_display_d.c \
		./ft_display_others.c \
		./ft_display_p.c \
		./ft_display_s.c \
		./ft_display_u.c \
		./ft_display_x.c \
		./ft_initialize.c \
		./ft_printf.c \
		./ft_send_display.c \
		./parser_flags.c

OBJ = $(SRC:.c=.o)

Ctab = -Wall -Wextra -Werror -I./libft

CC = gcc

.c.o:
			$(CC) $(Ctab) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
			@echo LIBFT START
			make -C $(LIB_DIR)
			@echo Copying $(LIBFT_A) to root
			cp $(LIB_DIR)$(LIBFT_A) .
			mv $(LIBFT_A) $(NAME)
			ar -rc $(NAME) $(OBJ)
			ranlib $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJ)
			make -C $(LIB_DIR) clean
			rm -rf a.out ./a.out.dSYM

fclean:		clean
			rm -f $(NAME)
			make -C $(LIB_DIR) fclean

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re
