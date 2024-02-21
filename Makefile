NAME = push_swap

NAMEB = checker

SRC =	main.c push_swap.c ft_split.c operations.c  tab_utils.c \
	ft_utils.c lst_utils.c ps_utils.c

SRCB = checker_main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c ps_utils.c\
	operations.c lst_utils.c push_swap.c ft_utils.c tab_utils.c ft_split.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o:%.c
	$(CC) $(CFLAGS) $< -c
clean:
	rm -f $(OBJ) $(OBJB) 
fclean: clean
	rm -f $(NAME) $(NAMEB)
re: fclean all
