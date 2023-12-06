# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icruces- < icruces-@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:06:04 by icruces-          #+#    #+#              #
#    Updated: 2023/12/06 17:09:41 by icruces-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libftprintf.a

all: $(NAME)

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all 