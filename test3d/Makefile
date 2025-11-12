EXEC_NAME = cub3d

SOURCES = main.c \
		  ft_abs.c

OBJECTS = $(SOURCES:.c=.o)

COMPILER = cc

COMPILATION_FLAGS = -Wall -Wextra -Werror

FSANITIZE_G3 = -fsanitize=address -g3

MLX_LIBRARY_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJECTS)
	$(COMPILER) $(COMPILATION_FLAGS) $(FSANITIZE_G3) -o $(EXEC_NAME) $(OBJECTS) $(MLX_LIBRARY_FLAGS)
%.o: %.c
	$(COMPILER) $(COMPILATION_FLAGS) $(FSANITIZE_G3) -o $@ -c $<

fclean: clean
	rm -f $(EXEC_NAME) 

clean:
	rm -f $(OBJECTS)

re: fclean all

.PHONY: fclean all clean re
