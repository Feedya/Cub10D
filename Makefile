NAME = cub3d

GCC = gcc

FLAGS = -Wall -Wextra -Werror -g -O0 -Wno-incompatible-pointer-types

#----------------------------------------------------------------------------------
# FLAGS MINILIBX (Configuration Statique)
#----------------------------------------------------------------------------------

MLX_DIR     = ./mlx_linux
# Le chemin vers le header pour que le compilo trouve "mlx.h"
INCLUDES    = -I$(MLX_DIR) -I/usr/include

# On pointe vers le .a et on lie les bibliothèques système Linux
# Note: L'ordre est important, le .a et -lmlx doivent être là
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

#----------------------------------------------------------------------------------
# DIRECTIONS (Tes variables inchangées)
#----------------------------------------------------------------------------------
#FIRST PARTS
#--------------------------------------------------------------
CHECK_EVERYTHIN_DIR = first_part/check_everything
UTILS_DIR = first_part/utils
GAME_UTILS_DIR = first_part/utils/game_utils
MAP_UTILS_DIR = first_part/utils/map_utils
CHECK_RGB_DIR = first_part/parsing/check_RGB
CHECK_MAP_DIR = first_part/parsing/check_map
PARSING_DIR = first_part/parsing
READ_FILE_DIR = first_part/read_file
CHECK_FILENAME_DIR = $(CHECK_EVERYTHIN_DIR)/check_filename
TAKE_MAP_FROM_FILE_DIR = first_part/take_map_from_file
CHECK_FILE_DIR = $(CHECK_EVERYTHIN_DIR)/check_file
CREATE_GAME_STRUCT_AND_FILL_DIR = first_part/create_game_struct_and_fill
INIT_IMAGE_DIR = first_part/init_image
MLX_UTILS_DIR = first_part/utils/mlx_utils
#--------------------------------------------------------------
#SECOND PART
#--------------------------------------------------------------
SECOND_PART_DIR = second_part

GAME_LOOP_DIR = $(SECOND_PART_DIR)

KEY_PRESS_DIR = $(SECOND_PART_DIR)/key_press
#----------------------------------------------------------------------------------
# FICHIERS (Tes variables inchangées)
#----------------------------------------------------------------------------------

#FIRST PARTS
#--------------------------------------------------------------

INIT_IMAGE_SRC = $(INIT_IMAGE_DIR)/init_image.c
UTILS_SRC = $(UTILS_DIR)/utils.c $(UTILS_DIR)/malloc_utils.c\
            $(UTILS_DIR)/take_string_after_needle.c\
            $(MAP_UTILS_DIR)/map_utils.c

CHECK_MAP_SRC = $(CHECK_MAP_DIR)/check_map.c $(CHECK_MAP_DIR)/check_walls.c\
                $(CHECK_MAP_DIR)/check_charactere_map.c $(CHECK_MAP_DIR)/create_good_map.c

CHECK_RGB_SRC = $(CHECK_RGB_DIR)/fill_RGB.c $(CHECK_RGB_DIR)/check_RGB.c
GAME_UTILS_SRC = $(GAME_UTILS_DIR)/create_game.c $(GAME_UTILS_DIR)/free_game.c
CHECK_EVERYTHIN_SRC = $(CHECK_EVERYTHIN_DIR)/check_everything.c
READ_FILE_SRC = $(READ_FILE_DIR)/read_file.c
PARSING_SRC = $(PARSING_DIR)/parsing.c $(PARSING_DIR)/put_player_information.c
CHECK_FILENAME_SRC = $(CHECK_FILENAME_DIR)/check_filename.c
TAKE_MAP_FROM_FILE_SRC = $(TAKE_MAP_FROM_FILE_DIR)/take_map_from_file.c\
                            $(TAKE_MAP_FROM_FILE_DIR)/malloc_map.c\
                            $(TAKE_MAP_FROM_FILE_DIR)/fill_map.c

CHECK_FILE_SRC = $(CHECK_FILE_DIR)/check_ceiling_and_floor.c $(CHECK_FILE_DIR)/check_texture.c

CREATE_GAME_STRUCT_AND_FILL_SRC = $(CREATE_GAME_STRUCT_AND_FILL_DIR)/create_game_struct_and_fill.c\
            $(CREATE_GAME_STRUCT_AND_FILL_DIR)/fill_wall_texture.c

MLX_UTILS_SRC = $(MLX_UTILS_DIR)/destroy_mlx.c

#--------------------------------------------------------------
#SECOND PART
#--------------------------------------------------------------

GAME_LOOP_SRC = $(GAME_LOOP_DIR)/game_loop.c $(GAME_LOOP_DIR)/dda_algo.c\
	$(GAME_LOOP_DIR)/put_ray_values.c

KEY_PRESS_SRC = $(KEY_PRESS_DIR)/key_press.c

#----------------------------------------------------------------------------------
#----------------------------------------------------------------------------------

SRCS = main.c $(UTILS_SRC) $(CHECK_FILENAME_SRC) $(GAME_UTILS_SRC)\
        $(READ_FILE_SRC) $(TAKE_MAP_FROM_FILE_SRC)\
        $(CHECK_FILE_SRC) $(CHECK_EVERYTHIN_SRC)\
        $(CREATE_GAME_STRUCT_AND_FILL_SRC) $(PARSING_SRC)\
        $(CHECK_MAP_SRC) $(CHECK_RGB_SRC) $(INIT_IMAGE_SRC)\
		$(MLX_UTILS_SRC) $(GAME_LOOP_SRC) $(KEY_PRESS_SRC)

OBJS = $(SRCS:.c=.o)


#----------------------------------------------------------------------------------
# REGLES
#----------------------------------------------------------------------------------

all: $(NAME)

# Compilation finale : on ajoute $(MLX_FLAGS) après les $(OBJS)
$(NAME): $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Compilation des fichiers objets : on ajoute $(INCLUDES) pour trouver mlx.h
%.o: %.c
	$(GCC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re