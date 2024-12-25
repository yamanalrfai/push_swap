CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = libft
LIB = $(LIBDIR)/libft.a

OBJS = $(SRC:.c=.o)
SRC =	node_comande.c soet_algo.c main.c free_file.c cheek_in.c choose_sort.c tar_find.c tmp_thing.c until_stack.c num_cheek.c
NAME = push_swap

LIBSRC = $(addprefix $(LIBDIR)/, *.c)
all:  $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(LIB): $(LIBSRC)
	$(MAKE) -C $(LIBDIR)
$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)


clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(LIBDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all
$(LIB): $(wildcard $(LIBDIR)/*.c) $(wildcard $(LIBDIR)/*.h)
.PHONY: all clean fclean re
