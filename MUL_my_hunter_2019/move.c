/*
** EPITECH PROJECT, 2019
** move
** File description:
** move rect & bird
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

game_t move_bird(sfVector2f *pos, game_t game)
{
    pos->x = pos->x + game.speed_bird;
    if (pos->x > 2030) {
        game.life--;
        pos->x = 0;
        pos->y = rand() % 540;
    }
    return (game);
}

void move_bg(sfIntRect *rect_bg, int offset, int max_value)
{
    if (rect_bg->left == max_value - offset)
        rect_bg->left = 0;
    else
        rect_bg->left = rect_bg->left + offset;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left == max_value - offset)
        rect->left = 0;
    else
        rect->left = rect->left + rect->width;
}
