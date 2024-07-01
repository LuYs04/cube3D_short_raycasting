NAME = cub3D

SRC = main/main.c					\
	main/free_data.c				\
	utils/get_next_line.c			\
	utils/get_next_line_utils.c		\
	utils/utils_for_plyr.c			\
	utils/utils_for_getting_info1.c	\
	utils/utils_for_getting_info2.c	\
	utils/utils_for_getting_info3.c	\
	utils/utils_for_mlx.c			\
	utils/check.c					\
	utils/utils_for_lst.c			\
	init/mlx_init.c					\
	init/data_init.c				\
	raycasting/moving.c				\
	raycasting/drawing.c			\
	raycasting/draw_txtr.c			\
	raycasting/raycast.c			\
	raycasting/update.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

LIBFT = libft/libft.a

all : libftcomp $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

libftcomp :
	make -C libft all bonus

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJ)
	make -C libft clean

fclean : clean
	$(RM) $(NAME)
	make -C libft fclean

re : fclean all

.PHONY : re all fclean clean libftcomp