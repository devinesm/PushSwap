NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

RM      = rm -f

LIBFT_DIR      = ./libft
LIBFT          = $(LIBFT_DIR)/libft.a
FT_DPRINTF_DIR = ./ft_dprintf
FT_DPRINTF     = $(FT_DPRINTF_DIR)/libftdprintf.a

SRCS    =	src/ops/swap.c \
          	src/ops/push.c \
          	src/ops/rotate.c \
          	src/ops/reverse_rotate.c \
			src/sort/compute_disorder.c \
			src/sort/sort_complex.c \
			src/sort/sort_medium.c \
			src/sort/sort_simple.c \
			src/sort/sort_turk.c \
			src/sort/sort.c \
			src/utils/args_utils.c \
			src/utils/bench_print_helpers.c \
			src/utils/bench_utils.c \
			src/utils/sorts_utils.c \
			src/utils/sorts2_utils.c \
			src/utils/stack_utils.c \
			src/utils/turk_utils.c \
			src/utils/turk_utils2.c \
			src/bench.c \
			src/main.c \
			src/parse_args.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_DPRINTF):
	@$(MAKE) -C $(FT_DPRINTF_DIR)

$(NAME): $(LIBFT) $(FT_DPRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_DPRINTF_DIR) -lftdprintf -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(FT_DPRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(FT_DPRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
