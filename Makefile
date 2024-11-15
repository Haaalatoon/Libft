NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
SRC_BONUS = $(wildcard *_bonus.c)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus:
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
