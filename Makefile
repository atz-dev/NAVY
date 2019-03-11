##
## EPITECH PROJECT, 2018
## Navy
## File description:
## Makefile Navy
##

CFLAGS		=	-W -Wall -Wextra -Werror -I./include/ -g3

RM		=	rm -rf

SRCS		=	src/main.c				\
				src/error_handling.c	\
				src/functions.c			\
				src/usefull.c			\
				src/player_one.c		\
				src/player_two.c		\
				src/array_function.c    \
				src/parsing.c			\
				src/board.c				\
				src/getnextline.c		\
				src/game.c				\
				src/target.c			\
				src/file_handling.c

OBJS 		= $(SRCS:.c=.o)

NAME		=	navy

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $@ $^

clean:
	$(RM) $(OBJS)

fclean:    clean
	$(RM) $(NAME)

re:    fclean all
