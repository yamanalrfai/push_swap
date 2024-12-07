CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = libft
LIB = $(LIBDIR)/libft.a

OBJS = $(SRC:.c=.o)
SRC = node_comande.c soet_algo.c main.c free_file.c cheek_in.c choose_sort.c tar_find.c tmp_thing.c until_stack.c
NAME = push_swap

all: $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)

$(LIB):
	make -C $(LIBDIR)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBDIR)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re