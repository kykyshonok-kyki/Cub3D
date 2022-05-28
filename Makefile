NAME =	cub3D

SRC =	window_image.c \
		control.c \
		raycast_utils.c \
		parser_subfuncs.c \
		parser.c \
		files.c \
		textures.c \
		screenshot.c \
		raycast_steps.c \
		raycast.c \
		steps.c \
		sprite.c \
		window_image_utils.c \
		parser_utils.c \
		files_color.c \
		main_inits.c
SRC	+=	get_next_line.c \
		get_next_line_utils.c \
		main.c

INCLUDE	= Includes/
FLAGS	= -Wall -Wextra -Werror
CC		= gcc

LIBFT		= libft/libft.a
LIBFTPATH	= libft/

MINILIBX		= minilibx/libmlx.a
MINILIBXPATH	= minilibx/

SCREEN	= screen.bmp

$(NAME): $(SRC)
	make -C $(LIBFTPATH)
	make -C $(MINILIBXPATH)
	$(CC) -framework OpenGL -framework AppKit -I$(MINILIBXPATH) $(MINILIBX) -I$(INCLUDE) -I$(LIBFTPATH) $(LIBFT) $(SRC) -o $(NAME)

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	make fclean -C $(LIBFTPATH)
	make clean -C $(MINILIBXPATH)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f $(SCREEN)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: