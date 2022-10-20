NAME = push_swap

SRCS = 	 main.c push_utils.c parsing.c parsing2.c errors.c sort.c  moves.c\

OBJS = ${SRCS:.c=.o}

CC		= gcc -g
#CC		= gcc -g -fsanitize=address
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
