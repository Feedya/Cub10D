#ifndef HEAD_H
#define HEAD_H

#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "mlx_linux/mlx.h"

/*valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-report.txt \*/

#define WINDOW_LARGEUR 1500
#define WINDOW_LONGUEUR 1500

//vitesse de deplacement
#define MOVE_SPEED 0.1

//vitesse de tournage
#define ROT_SPEED 0.05

#define TEXTURE_LARGEUR 128

typedef struct t_texture
{
    char *ea;
    char *we;
    char *so;
    char *no;
}   t_texture;

typedef struct t_ceiling
{
    char *RGB;
    int R;
    int G;
    int B;
}   t_ceiling;

typedef struct t_floor
{
    char *RGB;
    int R;
    int G;
    int B;
}   t_floor;

typedef struct t_ceiling_floor
{
    t_floor floor;
    t_ceiling ceiling;
}   t_ceiling_floor;

typedef struct t_player_position
{
    int x;
    int y;
    float   f_x;
    float   f_y;
} t_player_position;

typedef struct t_player_view
{
    //pour la direction
    float dir_x;
    float dir_y;
    //plan de la camera FOV
    float plane_x;
    float plane_y;
} t_player_view;

typedef struct t_player_info
{
    t_player_view view;
    t_player_position position;
} t_player_info;

typedef struct t_mlx
{
    void *mlx;
    void *win;
} t_mlx;

typedef struct t_image
{
    char    *direction;
    void    *image; //l image que mlx renvoie
    //memoire
    char    *addr;  //adresse de l imge pour pouvoir etre prcis couleur
    int     bits_per_pixel; //pour la couleur RGB + transparent 8 bits chaqun donc 32 en tout
    int     line_length; //pas encore compris mais en lien avec la memoire
    int     endian;
    //image info
    int     width;
    int     height;
} t_image;

//pour le DDA
//ca sera le rayon qu on va lancer pour chaque colonne de
//ma window 
typedef struct t_ray
{
    //direction du rayon
    double rayDirX;
    double rayDirY;
    //de la d ou part le rayon
    int    mapX;
    int    mapY;
    //compteur de combien on a avancer
    double sideDistX;
    double sideDistY;
    //la longuer que le rayon doit passer pour atteindre la prochaine case
    double deltaDistX;
    double deltaDistY;
    //direction du pas
    int    stepX;
    int    stepY;
    //pour mur perependiculaire
    //sert a enlever le fish eye je ne sais pas comment 
    float perp_wall_dist;
    int    side; // 0 pour Est/Ouest, 1 pour Nord/Sud
} t_ray;

//structure globale qui aura tout a l interieur
typedef struct t_game
{
    //la map
    char **map;
    //images pour les murs
    t_image wall_images[4];
    t_image background;
    t_texture   *wall_texture;
    //RGB du mur et du sol
    t_ceiling_floor *ceiling_floor;
    //info personnage
    t_player_info *player_info;
    //fenetre
    t_mlx *mlx;
    //pour dda
    t_ray ray;
} t_game;

//----------------------------------------------------------------------------------
//FIRST PART FIRST PART FIRST PART
//----------------------------------------------------------------------------------
//CHECK EVERYTHING
//----------------------------------------------------------------------------------

int check_everything(char *file);

//CHECKER MAP

int check_texture(char *file);
int check_ceiling_and_floor(char *file);

//check filename

int check_filename(char *name);

//----------------------------------------------------------------------------------
//CREATE_GAME_STRUCT_AND_FILL
//----------------------------------------------------------------------------------

t_game  *create_game_struct_and_fill(char **map, char *file);
int fill_wall_texture(t_game *game, char *file);

//----------------------------------------------------------------------------------
//PARSING
//----------------------------------------------------------------------------------

int parsing(t_game *game);

void    put_player_information(t_player_view *view, t_player_position *player, char **map);

//RGB CHECKER

int fill_rgb(t_ceiling *ceiling, t_floor *floor);
int check_RGB(t_ceiling ceiling, t_floor floor);

//MAP CHECKER

int check_if_closed(char **map);
char **check_map(char **map);
int check_charactere_map(char **map);

char    **create_good_map(char **map);
//----------------------------------------------------------------------------------
//READ_FILE
//----------------------------------------------------------------------------------

char    *read_file(char *filename);

//----------------------------------------------------------------------------------
//UTILS
//----------------------------------------------------------------------------------

int ft_strlen(char *str);
char    *create_string(char *str);
int str_compare(char *str, char *needle, int taille);
void jump_spaces(char *str, int *index);
void    free_double_char_size(char **map, int size);
void    exit_mit_text(char *str, int number);
void    free_double_char(char **tab);
char    *take_string_after_needle(char *file, char *needle);
int ft_atoi(char *str);
int comparer_string(char *str, char *str_two);

//MALLOC_UTILS

void *ft_realloc(void *ptr, size_t new_size, size_t old_size);
void *ft_calloc(size_t type, size_t taille);

//GAME UTILS

t_game *malloc_game(char **map);
void    free_game(t_game *game);

//MAP UTILS

int	is_character_of_map(char c);
int count_taille_of_double_char(char **map);
int find_longest_line(char **map);

//----------------------------------------------------------------------------------
//TAKE MAP FROM FILE
//----------------------------------------------------------------------------------

char    **take_map_from_file(char *file);
char	**malloc_map(char *str, int index);
void    fill_map(char *str, int i, char **map);

//----------------------------------------------------------------------------------
//INIT_IMAGE
//----------------------------------------------------------------------------------

int init_image(t_game *game);
int create_background_img(t_game *game);

//----------------------------------------------------------------------------------
//MLX UTILS 
//----------------------------------------------------------------------------------

void    destroy_mlx(t_mlx *mlx_struct);
void    destroy_all_images(t_game *game);

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//SECOND PART SECOND PART
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//GAME_LOOP
int game_loop(t_game *game);
//DDA ALGO
int dda_algo(t_game *game);
//PUT RAYS VALUES
int put_ray_values(t_game *game, int column);

//----------------------------------------------------------------------------------
//KEY PRESS 
//----------------------------------------------------------------------------------
int    key_press(int keycode, t_game *game);


#endif