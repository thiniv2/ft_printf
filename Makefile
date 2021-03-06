# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thini-42 <thinguye@student.42.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 15:24:45 by thinguye          #+#    #+#              #
#    Updated: 2021/03/03 17:58:01 by thini-42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_DIR = src/
SRC_FILES = ft_printf.c \
			print_c.c \
			print_s.c \
			print_d.c \
			print_x.c \
			print_o.c \
			print_p.c \
			print_u.c \
			print_f.c \
			print_zeros.c \
			read_format.c \
			call_identifiers.c \
			check_max_minwth.c \
			check_precision.c \
			ft_itoa_base.c \
			ft_putnbr_intmax.c \
			lenght_modifier.c \
			unsigned_convs.c \
			print_percent.c \
			ft_ftoa.c
SOURCES = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC_FILES:.c=.o)
HDR = includes/ft_printf.h
LIB = libft/libft.a
FLAG = -Wall -Wextra -Werror

all: $(NAME)

# must add -I flag before $(HDR) if compiling with macos

$(NAME):
	@ make -C libft
	@ make -C libft clean
	@ gcc $(FLAG) -c $(SOURCES) -I $(HDR)
	@ cp $(LIB) $(NAME)
	@ ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ) includes/ft_printf.h.gch
	@echo deleted .o files

fclean: clean
	rm -rf $(NAME) a.out

re: fclean all
