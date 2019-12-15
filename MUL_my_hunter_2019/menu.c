/*
** EPITECH PROJECT, 2019
** menu
** File description:
** everything related to menu display
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

game_t menu_click_management(game_t game, sfRenderWindow *window)
{
    if (game.x > 703 && game.x < 1219 &&
        game.y > 920 && game.y < 1013) {
        game.game_over = 0;
        game.soundtrack = sfMusic_createFromFile("game.ogg");
        sfMusic_play(game.soundtrack);
        game.pos.x = -110;
    }
    if (game.x > 1834 && game.x < 1888 &&
        game.y > 25 && game.y < 79)
        sfRenderWindow_close(window);
    return (game);
}

game_t menu_sound(game_t game, sfRenderWindow *window)
{
    if (game.event.type == sfEvtMouseMoved) {
        game.x = game.event.mouseMove.x;
        game.y = game.event.mouseMove.y;
        if (game.x > 703 && game.x < 1219 &&
            game.y > 920 && game.y < 1013) {
            game.notification = sfMusic_createFromFile("notif.ogg");
            sfMusic_play(game.notification);
        }
        if (game.x > 1834 && game.x < 1888 &&
            game.y > 25 && game.y < 79) {
            game.notification = sfMusic_createFromFile("notif.ogg");
            sfMusic_play(game.notification);
        }
    }
    return (game);
}

game_t menu(game_t game, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, game.sprite_menu, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_pollEvent(window, &game.event)) {
        game = menu_sound(game, window);
        if (game.event.type == sfEvtMouseButtonReleased) {
            game.x = game.event.mouseButton.x;
            game.y = game.event.mouseButton.y;
            game = menu_click_management(game, window);
        }
        if (game.event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return (game);
}
