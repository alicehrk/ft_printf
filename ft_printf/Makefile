# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harkim <harkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 21:50:31 by harkim            #+#    #+#              #
#    Updated: 2023/02/26 22:57:23 by harkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_put_csdiu.c ft_put_px.c

OBJS = $(SRCS:.c=.o)

INC = ./ft_printf.h

all : $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) -I $(INC) -o $@ $^

$(NAME) : $(OBJS)
	ar rcs $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY = all clean fclean re