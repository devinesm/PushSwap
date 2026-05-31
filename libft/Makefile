NAME    = libft.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Source and Object files
SRC     = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	  ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  ft_atoi.c ft_calloc.c ft_strdup.c \
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	  ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	  ft_lstmap.c
OBJ     = $(SRC:.c=.o)

# Tools
RM      = rm -f
AR      = ar rcs

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Pattern rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	$(RM) $(OBJ)

# Remove object files and the library
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
