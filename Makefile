NAME    =       push_swap
CC      =       cc
CFLAGS  =       -Wall -Wextra -Werror

SRCS    =       push_swap.c action.c action2.c list_utils.c
OBJS    =       $(SRCS:.c=.o)

all:    $(NAME)

$(NAME):        $(SRCS)
        @$(CC) $(CFLAGS) $(SRCS) -o push_swap
		clean

clean:
        @rm -f $(OBJS)

fclean: clean
        @rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
