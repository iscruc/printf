# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icruces- < icruces-@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:06:04 by icruces-          #+#    #+#              #
#    Updated: 2024/01/10 19:38:42 by icruces-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = printf.c printf_utils.c 

OBJS = $(SRC:.c=.o)

CC = gcc

RM = rm -rf

NAME = libftprintf.a
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
all: $(NAME)

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
