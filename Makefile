# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 23:47:06 by kroyce            #+#    #+#              #
#    Updated: 2020/12/01 23:47:27 by kroyce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = gcc -Wall -Werror -Wextra -I.

HEADER = ft_printf.h

SRC = ft_printf.c check.c parser.c processor/handle_percent.c \
		processor/handle_char.c processor/handle_hex.c \
		processor/handle_int.c processor/handle_pointer.c \
		processor/handle_str.c processor/handle_unsigned.c \
		utils/count_digits.c utils/ft_atoi.c utils/ft_itoa.c \
		utils/ft_isdigit.c utils/ft_strdup.c utils/ft_strjoin.c \
		utils/ft_strlen.c utils/ft_substr.c utils/ft_unsigned_itoa.c \
		utils/pf_putchar.c utils/pf_putstr.c utils/ft_strncmp.c

OSRC = $(SRC:.c=.o)

%.o: %.c $(HEADER)
	$(FLAGS) -c $< -o $@

all: $(NAME) $(OBJ)

$(NAME): $(OSRC)
	ar rc $(NAME) $(OSRC)
	ranlib $(NAME)

clean:
	rm -rf $(OSRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
