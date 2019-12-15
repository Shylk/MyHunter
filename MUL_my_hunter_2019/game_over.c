/*
** EPITECH PROJECT, 2019
** game_over
** File description:
** end game screen management
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
#include <SFML/Audio.h>

void set_and_draw(game_t game, sfRenderWindow *window)
{
    sfText_setPosition(game.text, game.pos_text);
    sfText_setPosition(game.text_score, game.pos_score);
    sfText_setPosition(game.text_best_score, game.pos_best_score);
    sfRenderWindow_drawText(window, game.text, NULL);
    sfRenderWindow_drawText(window, game.text_score, NULL);
    sfRenderWindow_drawText(window, game.text_best_score, NULL);
    sfRenderWindow_display(window);
}

game_t game_over_values(game_t game)
{
    game.pos_text.x = 600;
    game.pos_text.y = 620;
    game.pos_score.x = 1200;
    game.pos_score.y = 620;
    game.pos_best_score.x = 650;
    game.pos_best_score.y = 900;
    game.speed_bird = 50;
    return (game);
}

game_t reset(game_t game)
{
    game.game_over = 0;
    game.life = 3;
    game.pos_text.x = 50;
    game.pos_text.y = 965;
    game.pos_score.x = 300;
    game.pos_score.y = 965;
    game.pos_best_score.x = 1325;
    game.pos_best_score.y = 965;
    game.score = 0;
    game.pos.x = -110;
    return (game);
}

game_t draw_reset_text(game_t game, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, game.text, NULL);
    sfRenderWindow_drawText(window, game.text_score, NULL);
    sfRenderWindow_drawText(window, game.text_best_score, NULL);
    return (game);
}

game_t game_over_screen(game_t game, sfRenderWindow *window)
{
    if (game.game_over == 1 && game.life == 0) {
        game = game_over_values(game);
        sfRenderWindow_drawSprite(window, game.sprite_go, NULL);
        set_and_draw(game, window);
        while (sfRenderWindow_pollEvent(window, &game.event)) {
            if (game.event.type == sfEvtMouseButtonReleased ||
                game.event.type == sfEvtKeyReleased) {
                game = click_game_over(game, window);
            }
            if (game.event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
    }
    return (game);
}
