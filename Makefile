NAME = cub3d

CC = gcc

ADDITIONAL_FLAGS = -fsanitize=address -g 

C_FLAGS = -g

MLX_FLAGS =  -Lmlx_linux -lmlx_Linux -lX11 -lXext -lm

FUNCTIONS =	src/my_mlx_pixel_put.c\
			src/get_player_position.c\
			src/cub3d.c\
			src/get_keys.c\
			src/3d_projection.c\
			src/3d_projection_utils.c\
			src/set_directions.c\
			src/images_xpm.c\
			src/moves/move_forward.c\
			src/moves/move_left.c\
			src/moves/move_right.c\
			src/moves/move_backword.c\
			src/destroy_window.c\
			src/textures.c\
			map_parsing/libft/ft_atoi.c\
			map_parsing/libft/ft_strnstr.c\
			map_parsing/libft/ft_calloc.c\
			map_parsing/libft/ft_strlen.c\
			map_parsing/libft/ft_strncmp.c\
			map_parsing/libft/ft_strjoin.c\
			map_parsing/libft/ft_strtrim.c\
			map_parsing/libft/ft_putchar_fd.c\
			map_parsing/libft/ft_putstr_fd.c\
			map_parsing/cub_utils.c\
			map_parsing/errors.c\
			map_parsing/textur.c\
			map_parsing/color.c\
			map_parsing/get_next_line_utils.c\
			map_parsing/parsing.c\
			map_parsing/get_next_line.c\
			map_parsing/read_map.c\
			map_parsing/check_maze.c\
			map_parsing/position.c\
		
RM = rm -rf

all		:	$(NAME) 

$(NAME) : $(FUNCTIONS)
			$(CC) $(C_FLAGS) $(FUNCTIONS) $(MLX_FLAGS) -o $(NAME) 

clean	:	
			$(RM) $(NAME)
fclean	:	clean

re 		:	fclean all
