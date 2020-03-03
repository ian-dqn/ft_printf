# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 17:22:25 by iaduquen          #+#    #+#              #
#    Updated: 2020/02/29 16:42:51 by iaduquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

SRCS =	ft_isprint.c ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcpy.c ft_strrchr.c ft_atoi.c \
		ft_isascii.c ft_memchr.c ft_memset.c ft_strlen.c ft_tolower.c ft_bzero.c ft_isdigit.c \
		ft_memcmp.c ft_strchr.c ft_strncmp.c ft_toupper.c ft_isalnum.c ft_isprint.c ft_memcpy.c \
		ft_strlcat.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_substr.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c \
		ft_strmapi.c ft_intcount.c ft_compar.c ft_hexacount.c ft_itoa_base.c ft_rev_str.c \

SRCB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstiter_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJB = $(SRCB:.c=.o)

HEADER = ./

%.o: %.c
	gcc -Wall -Wextra -Werror -c -I$(HEADER) -o $@ $<

all:    $(NAME)	

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS) $(OBJB)

fclean:     clean
	/bin/rm -f $(NAME)

re: fclean all

bonus: all $(OBJB)
	ar rc $(NAME) $(OBJB) $(OBJS)
	ranlib $(NAME)
	
.PHONY: all clean fclean re bonus
