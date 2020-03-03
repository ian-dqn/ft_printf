# **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2020/01/08 10:09:58 by iaduquen          #+#    #+#              #
#    Updated: 2020/03/02 15:28:16 by iaduquen         ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf_utils.c ft_printf.c algo.c bloc.c utils.c

OBJS		= $(SRCS:.c=.o)

LIBFT		= ./includes/libft

HEADER		= ./

%.o: %.c
	gcc -c -I$(HEADER) -o $@ $<

all: makelib $(NAME)
	
$(NAME): $(OBJS)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)	
	ranlib $(NAME)

makelib: 
	make -C $(LIBFT)

clean:
	/bin/rm -f $(OBJS)
	make clean -C $(LIBFT)


fclean:     clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus
