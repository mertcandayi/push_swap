NAME	=	push_swap
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	push_swap.c push.c swap.c rotate.c \
				reverse_rotate.c utils.c sort.c \
				list_utils.c
OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean re