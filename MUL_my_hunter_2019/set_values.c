/*
** EPITECH PROJECT, 2019
** texture
** File description:
** management of texture and sprite
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

game_t set_values_struct_2(game_t game)
{
    game.speed_bird = 50;
    game.pos_life.x = 550;
    game.pos_life.y = 965;
    game.life = 3;
    game.pos_replay.x = 570;
    game.pos_replay.y = 430;
    game.rect_bg.left = 0;
    game.rect_bg.top = 0;
    game.rect_bg.width = 2259;
    game.rect_bg.height = 1050;
    return (game);
}

game_t set_values_struct(game_t game)
{
    game = set_values_struct_2(game);
    game.speed_wings = 0.20;
    game.game_over = 2;
    game.x = 0;
    game.y = 0;
    game.point = 0;
    game.score = 0;
    game.pos.x = 0;
    game.pos.y = 0;
    game.pos_text.x = 50;
    game.pos_text.y = 965;
    game.pos_score.x = 300;
    game.pos_score.y = 965;
    game.pos_best_score.x = 1325;
    game.pos_best_score.y = 965;
    game.rect.top = 0;
    game.rect.left = 0;
    game.rect.width = 110;
    game.rect.height = 110;
    return (game);
}
