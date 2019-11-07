# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kparis <kparis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 15:54:25 by kparis            #+#    #+#              #
#    Updated: 2019/11/07 12:38:45 by kparis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c \
		ft_process_percent.c \
		ft_process_bigx.c \
		ft_process_x.c \
		ft_process_d.c \
		ft_process_p.c \
		ft_process_s.c \
		ft_process_u.c \
		ft_process_c.c \
		ft_process_star.c \
		ft_process_basics.c \
		ft_trunc_str.c \
		ft_check_useless_0.c \
		ft_remove_doubledash.c \
		ft_process_dot.c \
		ft_display_str.c \
		ft_replace_flags.c \
		ft_process_dash.c \
		ft_process_num.c

LIBFT = libft

OBJ = $(SRC:.c=.o)
OBJTEST = $(SRC:.testc=.o)
CFLAGS += -Wall -Wextra -Werror -I./
CC = gcc
.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
.testc.o:
		$(CC) -c $< -o $(<:.c=.o)
$(NAME):	$(OBJ)
			make -C ${LIBFT}
			ar -rc $(NAME) $(OBJ)
all:		$(NAME)
test:
			make -C ${LIBFT}
			ar -rc $(NAME) $(OBJTEST)
all:		$(NAME)
clean:
			rm -f $(OBJ)
			rm -f a.out
			make clean -C ${LIBFT}
fclean:		clean
			rm -f $(NAME)
			make fclean -C ${LIBFT}
re:		fclean all
.PHONY:		all clean fclean re
