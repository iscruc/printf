# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icruces- < icruces-@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:06:04 by icruces-          #+#    #+#              #
#    Updated: 2023/12/07 18:12:25 by icruces-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = printf.h  printf.c printf_utils.c 

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