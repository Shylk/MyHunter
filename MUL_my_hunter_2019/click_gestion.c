/*
** EPITECH PROJECT, 2019
** action mangement
** File description:
** handle click & game_over
*/

#include <stdlib.h>
#include <stdio.h>
#include "structure.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Time.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/FontInfo.h>
#include <SFML/Audio.h>

game_t game_over_management(game_t game)
{
    game.game_over = 1;
    sfMusic_stop(game.soundtrack);
    game.game_over_sound = sfMusic_createFromFile("game_over.ogg");
    sfMusic_play(game.game_over_sound);
    return (game);
}

game_t click(game_t game)
{
    if (game.x > game.pos.x  && game.x < game.pos.x + 110 &&
        game.y < game.pos.y + 110 && game.y > game.pos.y - 110) {
        game.score++;
        game.hit = sfMusic_createFromFile("hit.ogg");
        sfMusic_play(game.hit);
        game.pos.y = rand() % 970;
        game.pos.x = -110;
        game.speed_bird += 2;
        game.speed_wings -= 0.00025;
    } else {
        game.fail = sfMusic_createFromFile("fail.ogg");
        sfMusic_play(game.fail);
        game.life--;
        if (game.life == 0)
            game = game_over_management(game);
    }
    return (game);
}
