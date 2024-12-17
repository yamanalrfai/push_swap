CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = libft
LIB = $(LIBDIR)/libft.a

OBJS = $(SRC:.c=.o)
SRC =	node_comande.c soet_algo.c main.c free_file.c cheek_in.c choose_sort.c tar_find.c tmp_thing.c until_stack.c num_cheek.c
NAME = push_swap
LIBSRC = ft_getlen.c get_next_line_utils.c get_next_line.c \
         ft_putnbr_fd_lower.c ft_putadd_fd.c ft_printf.c \
         ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c \
         ft_putstr_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c \
         ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c \
         ft_strdup.c ft_calloc.c ft_atoi.c ft_strnstr.c \
         ft_memcmp.c ft_memchr.c ft_strncmp.c ft_strrchr.c \
         ft_strchr.c ft_toupper.c ft_tolower.c ft_strlcpy.c \
         ft_strlcat.c ft_memmove.c ft_memcpy.c ft_bzero.c \
         ft_memset.c ft_strlen.c ft_isprint.c ft_isascii.c \
         ft_isalnum.c ft_isdigit.c ft_isalpha.c
LIBSRC := $(addprefix $(LIBDIR)/, $(LIBSRC))
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