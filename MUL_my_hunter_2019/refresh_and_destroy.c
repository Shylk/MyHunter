/*
** EPITECH PROJECT, 2019
** refresh and destroy
** File description:
** display and destroy window management
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Time.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <SFML/System/Vector2.h>
#include "structure.h"
#include <SFML/Graphics/FontInfo.h>

void set_refresh(game_t game)
{
    game.pos_sprite_life.x = 750;
    game.pos_sprite_life.y = 989;
    game.pos_sprite_life2.x = 800;
    game.pos_sprite_life2.y = 989;
    game.pos_sprite_life3.x = 850;
    game.pos_sprite_life3.y = 989;
    sfText_setString(game.text_score, my_int_to_str(game.score));
    sfSprite_setPosition(game.sprite, game.pos);
    sfSprite_setPosition(game.sprite_life, game.pos_sprite_life);
    sfSprite_setPosition(game.sprite_life2, game.pos_sprite_life2);
    sfSprite_setPosition(game.sprite_life3, game.pos_sprite_life3);
    sfSprite_setTextureRect(game.sprite, game.rect);
    sfSprite_setTextureRect(game.sprite_bg, game.rect_bg);
}

void draw_sprite(game_t game, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, game.sprite_bg, NULL);
    sfRenderWindow_drawSprite(window, game.sprite, NULL);
    if (game.life >= 1) {
        sfRenderWindow_drawSprite(window, game.sprite_life, NULL);
        if (game.life >= 2) {
            sfRenderWindow_drawSprite(window, game.sprite_life2, NULL);
            if (game.life >= 3)
                sfRenderWindow_drawSprite(window, game.sprite_life3, NULL);
        }
    }
}

void draw_text(game_t game, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, game.text, NULL);
    sfRenderWindow_drawText(window, game.text_score, NULL);
    sfRenderWindow_drawText(window, game.text_best_score, NULL);
    sfRenderWindow_drawText(window, game.text_life, NULL);
}

game_t refresh(game_t game, sfRenderWindow *window)
{
    sfClock_restart(game.clock);
    sfRenderWindow_clear(window, sfBlack);
    set_refresh(game);
    draw_sprite(game, window);
    draw_text(game, window);
    sfRenderWindow_display(window);
    return (game);
}
