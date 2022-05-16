NAME = pipex

CC	=	cc

CFLAGS = -Wall -Wextra -Werror -g

ALL_SRCS = $(wildcard *.c)

SRCS = $(filter-out $(BONUS_SRCS), $(ALL_SRCS))

OBJS = $(patsubst %.c, %.o, $(SRCS))

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

bonus:	all

.PHONY: all clean fclean re bonus