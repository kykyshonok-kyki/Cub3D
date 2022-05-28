NAME = libft.a

SRC =	ft_atoi.c \
		ft_memccpy.c \
		ft_putstr_fd.c \
		ft_strncmp.c \
		ft_bzero.c \
		ft_memchr.c \
		ft_split.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_isalnum.c \
		ft_memcpy.c \
		ft_strdup.c \
		ft_strtrim.c \
		ft_isalpha.c \
		ft_memmove.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_isascii.c \
		ft_memset.c \
		ft_strlcat.c \
		ft_tolower.c \
		ft_isdigit.c \
		ft_putchar_fd.c \
		ft_strlcpy.c \
		ft_toupper.c \
		ft_isprint.c \
		ft_putendl_fd.c \
		ft_strlen.c \
		ft_itoa.c \
		ft_putnbr_fd.c \
		ft_strmapi.c \
		ft_itohx.c \
		ft_puthx_fd.c \
		ft_numlen.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c

INCLUDE = libft.h

OBJ =	ft_atoi.o \
		ft_memccpy.o \
		ft_putstr_fd.o \
		ft_strncmp.o \
		ft_bzero.o \
		ft_memchr.o \
		ft_split.o \
		ft_strnstr.o \
		ft_calloc.o \
		ft_memcmp.o \
		ft_strchr.o \
		ft_strrchr.o \
		ft_isalnum.o \
		ft_memcpy.o \
		ft_strdup.o \
		ft_strtrim.o \
		ft_isalpha.o \
		ft_memmove.o \
		ft_strjoin.o \
		ft_substr.o \
		ft_isascii.o \
		ft_memset.o \
		ft_strlcat.o \
		ft_tolower.o \
		ft_isdigit.o \
		ft_putchar_fd.o \
		ft_strlcpy.o \
		ft_toupper.o \
		ft_isprint.o \
		ft_putendl_fd.o \
		ft_strlen.o \
		ft_itoa.o \
		ft_putnbr_fd.o \
		ft_strmapi.o \
		ft_itohx.o \
		ft_puthx_fd.o \
		ft_numlen.o \
		ft_lstadd_back.o \
		ft_lstadd_front.o \
		ft_lstclear.o \
		ft_lstdelone.o \
		ft_lstiter.o \
		ft_lstlast.o \
		ft_lstnew.o \
		ft_lstsize.o

FLAGS = -Wall -Wextra -Werror

CC = gcc

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -I $(INCLUDE) -c $<

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ) $(OBJB)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all