CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = libft
LIB = $(LIBDIR)/libft.a

OBJS = $(SRC:.c=.o)
SRC =	node_comande.c soet_algo.c main.c free_file.c cheek_in.c choose_sort.c tar_find.c tmp_thing.c until_stack.c num_cheek.c \
		libft/ft_getlen.c libft/ft_putnbr_fd_lower.c libft/ft_putadd_fd.c libft/ft_printf.c libft/ft_putnbr_fd.c libft/ft_putendl_fd.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_striteri.c libft/ft_strmapi.c libft/ft_itoa.c libft/ft_split.c libft/ft_strtrim.c libft/ft_strjoin.c libft/ft_substr.c libft/ft_strdup.c libft/ft_calloc.c libft/ft_atoi.c libft/ft_strnstr.c libft/ft_memcmp.c libft/ft_memchr.c libft/ft_strncmp.c libft/ft_strrchr.c libft/ft_strchr.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_memmove.c libft/ft_memcpy.c libft/ft_bzero.c libft/ft_memset.c libft/ft_strlen.c libft/ft_isprint.c libft/ft_isascii.c libft/ft_isalnum.c libft/ft_isdigit.c libft/ft_isalpha.c
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