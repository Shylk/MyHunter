/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Time.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>

typedef struct game
{
    sfTexture *texture;
    sfTexture *texture_bg;
    sfTexture *texture_go;
    sfTexture *texture_life;
    sfTexture *texture_life2;
    sfTexture *texture_life3;
    sfTexture *texture_menu;
    sfSprite *sprite;
    sfSprite *sprite_bg;
    sfSprite *sprite_go;
    sfSprite *sprite_life;
    sfSprite *sprite_life2;
    sfSprite *sprite_life3;
    sfSprite *sprite_menu;
    sfEvent event;
    sfVector2f pos;
    sfVector2f pos_text;
    sfVector2f pos_score;
    sfVector2f pos_best_score;
    sfVector2f pos_life;
    sfVector2f pos_sprite_life;
    sfVector2f pos_sprite_life2;
    sfVector2f pos_sprite_life3;
    sfVector2f pos_replay;
    sfVector2f pos_mouse;
    sfIntRect rect;
    sfIntRect rect_bg;
    sfText *text;
    sfText *text_score;
    sfText *text_best_score;
    sfText *text_life;
    sfText *text_replay;
    sfColor sfBlack;
    sfFont *font;
    sfClock *clock;
    sfTime time;
    int score;
    int life;
    int x;
    int y;
    int point;
    int speed_bird;
    float speed_wings;
    float seconds;
    int game_over;
    sfMouseButtonEvent click;
    sfMusic *hit;
    sfMusic *soundtrack;
    sfMusic *fail;
    sfMusic *game_over_sound;
    sfMusic *notification;
} game_t;

game_t texture_sprite(game_t game, sfRenderWindow *window);
game_t destroy(game_t game, sfRenderWindow *window);
game_t set_values_struct(game_t game);
game_t set_values_struct_2(game_t game);
void move_rect(sfIntRect *rect, int offset, int max_value);
game_t text_management(game_t game, sfRenderWindow *window);
game_t text_creation(game_t game);
game_t text_set_string(game_t game);
game_t text_set_font(game_t game);
game_t text_set_position(game_t game);
char *my_revstr(char *str);
int my_evil_length(char *str);
char *my_int_to_str(int to_array);
game_t destroy(game_t game, sfRenderWindow *window);
game_t refresh(game_t game, sfRenderWindow *window);
game_t click(game_t game);
game_t game_over_screen(game_t game, sfRenderWindow *window);
game_t click_game_over(game_t game, sfRenderWindow *window);
game_t move_bird(sfVector2f *pos, game_t game);
void usage(char **argv);
int my_putstr(char const *str);
game_t menu(game_t game, sfRenderWindow *window);
game_t reset(game_t game);
game_t draw_reset_text(game_t game, sfRenderWindow *window);
