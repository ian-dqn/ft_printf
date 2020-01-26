# **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2020/01/08 10:09:58 by iaduquen          #+#    #+#              #
#    Updated: 2020/01/24 19:07:42 by iaduquen         ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_utils.c ft_printf.c

OBJS = $(SRCS:.c=.o)

HEADER = ./

%.o: %.c
	gcc -c -I$(HEADER) -o $@ $<

all:    $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean:     clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
