/*
** EPITECH PROJECT, 2019
** square
** File description:
** graphic square
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

game_t destroy(game_t game, sfRenderWindow *window)
{
    sfText_destroy(game.text);
    sfText_destroy(game.text_score);
    sfFont_destroy(game.font);
    sfSprite_destroy(game.sprite);
    sfSprite_destroy(game.sprite_bg);
    sfSprite_destroy(game.sprite_go);
    sfTexture_destroy(game.texture);
    sfTexture_destroy(game.texture_bg);
    sfTexture_destroy(game.texture_go);
    sfRenderWindow_destroy(window);
    sfClock_destroy(game.clock);
    return (game);
}

game_t analyse_events(sfRenderWindow *window, game_t game)
{
    while (sfRenderWindow_pollEvent(window, &game.event)) {
        if (game.event.type == sfEvtMouseButtonReleased) {
            game.x = game.event.mouseButton.x;
            game.y = game.event.mouseButton.y;
            game = click(game);
        }
        if (game.event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return (game);
}

int window_loop(game_t game, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        game.time = sfClock_getElapsedTime(game.clock);
        game.seconds = game.time.microseconds/ 1000000.0;
        if (game.seconds > 0.15) {
            game = analyse_events(window, game);
            move_rect(&game.rect, 110, 330);
            move_rect(&game.rect_bg, 2259, 9036);
            move_bird(&game.pos, game);
            if (game.game_over == 0 && game.life > 0)
                game = refresh(game, window);
            if (game.game_over == 1 && game.life == 0)
                game = game_over_screen(game, window);
            if (game.game_over == 2)
                game = menu(game, window);
        }
    }
    return (0);
}

void usage(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("     ./hunter [-h]\n\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("     The program is a game based on the duck hunt game\n");
        my_putstr("     You have to click on the bird");
        my_putstr(" (it also works by using your finger).\n");
        my_putstr("     Each time you hit the bird, the score goes up.\n");
        my_putstr("     The bird also goes faster at each hit.\n");
        my_putstr("     Be careful not to miss it !\n\n");
        my_putstr("USER INPUT\n");
        my_putstr("     Mouse : Left click.\n");
        my_putstr("     Screen : Your finger.\n");
        my_putstr("     Keyboard : Any button to restart.\n");
    } else {
    }
}

int main(int argc, char **argv)
{
    struct game game;
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;

    if (argc != 1)
        usage(argv);
    window = sfRenderWindow_create(mode, "MyHunter", sfResize | sfClose, NULL);
    game = set_values_struct(game);
    game = set_values_struct_2(game);
    game = texture_sprite(game, window);
    game = text_management(game, window);
    window_loop(game, window);
    destroy(game, window);
    return (0);
}
