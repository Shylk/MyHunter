/*
** EPITECH PROJECT, 2019
** game_over my hunter
** File description:
** 2nd file for game_over management
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

game_t click_game_over(game_t game, sfRenderWindow *window)
{
    game.x = game.event.mouseButton.x;
    game.y = game.event.mouseButton.y;
    if (game.x > 662 && game.x < 1180 &&
        game.y > 366 && game.y < 523 ||
        game.event.type == sfEvtKeyReleased) {
        game = reset(game);
        game = text_management(game, window);
        game = draw_reset_text(game, window);
        game.soundtrack = sfMusic_createFromFile("game.ogg");
        sfMusic_play(game.soundtrack);
        sfMusic_stop(game.game_over_sound);
    }
    return (game);
}
