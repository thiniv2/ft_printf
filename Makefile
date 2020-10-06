# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thinguye <thinguye@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 15:24:45 by thinguye          #+#    #+#              #
#    Updated: 2020/09/30 14:15:26 by thinguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_DIR = src/
SRC_FILES = ft_printf.c \
			print_char.c \
			read_format.c \
			call_identifiers.c \
			print_str.c \
			check_max_minwth.c \
			check_precision.c \
			print_d.c \
			print_zeros.c
SOURCES = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC_FILES:.c=.o)
HDR = -L includes/ft_printf.h
LIB = libft/libft.a
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@ make -C libft
	@ make -C libft clean
	@ gcc $(FLAG) -c $(SOURCES) -I $(HDR)
	@ cp $(LIB) $(NAME)
	@ ar rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ) includes/ft_printf.h.gch
	@echo deleted .o files

fclean: clean
	rm -rf $(NAME) a.out

re: fclean all
