PARSER = lib/parser.a
LIBFT = lib/libft/libft.a
OBJ_DIR = lib/obj

PARSER_SRCS =  src/parser.c \
                src/parse_elements.c \
                src/parse_map.c \
                src/validate_map.c

PARSER_OBJS = $(PARSER_SRCS:src/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -I lib/libft
RM = rm -f
AR = ar rcs

all: $(PARSER)

$(LIBFT):
	make -C lib/libft

$(PARSER): $(PARSER_OBJS) $(LIBFT)
	cp $(LIBFT) $(PARSER)
	$(AR) $(PARSER) $(PARSER_OBJS)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(PARSER_OBJS)
	make -C lib/libft clean

fclean: clean
	$(RM) $(PARSER)
	make -C lib/libft fclean

re: fclean all

.PHONY: all clean fclean re