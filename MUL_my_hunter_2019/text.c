/*
** EPITECH PROJECT, 2019
** text
** File description:
** everything related to text management
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

game_t text_creation(game_t game)
{
    game.text = sfText_create();
    game.text_score = sfText_create();
    game.text_best_score = sfText_create();
    game.text_life = sfText_create();
    game.text_replay = sfText_create();
    return (game);
}

game_t text_set_string(game_t game)
{
    sfText_setString(game.text, "Score : ");
    sfText_setString(game.text_score, my_int_to_str(game.score));
    sfText_setString(game.text_best_score, "Highest score : 42");
    sfText_setString(game.text_life, "Life : ");
    sfText_setString(game.text_replay, "Click or press any button to replay !");
    return (game);
}

game_t text_set_font(game_t game)
{
    sfText_setFont(game.text, game.font);
    sfText_setFont(game.text_score, game.font);
    sfText_setFont(game.text_best_score, game.font);
    sfText_setFont(game.text_life, game.font);
    sfText_setFont(game.text_replay, game.font);
    return (game);
}

game_t text_set_position(game_t game)
{
    sfText_setPosition(game.text, game.pos_text);
    sfText_setPosition(game.text_score, game.pos_score);
    sfText_setPosition(game.text_best_score, game.pos_best_score);
    sfText_setPosition(game.text_life, game.pos_life);
    sfText_setPosition(game.text_replay, game.pos_replay);
    return (game);
}

game_t text_management(game_t game, sfRenderWindow *window)
{
    game = text_creation(game);
    game.font = sfFont_createFromFile("arial.ttf");
    game = text_set_string(game);
    game = text_set_font(game);
    game = text_set_position(game);
    sfText_setCharacterSize(game.text, 70);
    sfText_setCharacterSize(game.text_score, 70);
    sfText_setCharacterSize(game.text_best_score, 70);
    sfText_setCharacterSize(game.text_life, 70);
    sfText_setCharacterSize(game.text_replay, 50);
    return (game);
}
