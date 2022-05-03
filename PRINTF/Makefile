# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 20:13:06 by ergrigor          #+#    #+#              #
#    Updated: 2022/04/08 22:35:26 by ergrigor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC	=	cc

CFLAGS = -Wall -Wextra -Werror

ALL_SRCS = $(wildcard *.c)

SRCS = $(filter-out $(BONUS_SRCS), $(ALL_SRCS))

OBJS = $(patsubst %.c, %.o, $(SRCS))

RM = rm -f

AR = ar rc

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

bonus:	all

.PHONY: all clean fclean re bonus
