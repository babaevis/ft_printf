# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 17:58:13 by kdeloise          #+#    #+#              #
#    Updated: 2020/12/01 01:36:27 by kroyce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


	
NAME = libftprintf.a

FLAGS = gcc -Wall -Werror -Wextra -I.

HEADER = ft_printf.h

SRC = ft_printf.c check.c parser.c processor.c  \
		handlers/handle_char.c handlers/handle_hex.c handlers/handle_percent.c \
		handlers/handle_int.c handlers/handle_pointer.c \
		handlers/handle_str.c handlers/handle_unsigned.c \
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
