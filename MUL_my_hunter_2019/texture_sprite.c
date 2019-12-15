/*
** EPITECH PROJECT, 2019
** texture sprite
** File description:
** everything related to texture and sprite management
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

game_t create_texture(game_t game)
{
    game.texture = sfTexture_createFromFile("bird_spritesheet.png", NULL);
    game.texture_bg = sfTexture_createFromFile("bg.png", NULL);
    game.texture_go = sfTexture_createFromFile("game_over_screen.png", NULL);
    game.texture_life =sfTexture_createFromFile("arrow.png", NULL);
    game.texture_life2 = sfTexture_createFromFile("arrow.png", NULL);
    game.texture_life3 = sfTexture_createFromFile("arrow.png", NULL);
    game.texture_menu = sfTexture_createFromFile("menu.png", NULL);
    return (game);
}

game_t create_sprite(game_t game)
{
    game.sprite_bg = sfSprite_create();
    game.sprite = sfSprite_create();
    game.sprite_go = sfSprite_create();
    game.sprite_life = sfSprite_create();
    game.sprite_life2 = sfSprite_create();
    game.sprite_life3 = sfSprite_create();
    game.sprite_menu = sfSprite_create();
    game.clock = sfClock_create();
    return (game);
}

game_t set_texture(game_t game)
{
    sfSprite_setTexture(game.sprite_go, game.texture_go, sfTrue);
    sfSprite_setTexture(game.sprite_bg, game.texture_bg, sfTrue);
    sfSprite_setTexture(game.sprite_life, game.texture_life, sfTrue);
    sfSprite_setTexture(game.sprite_life2, game.texture_life2, sfTrue);
    sfSprite_setTexture(game.sprite_life3, game.texture_life3, sfTrue);
    sfSprite_setTexture(game.sprite, game.texture, sfTrue);
    sfSprite_setTexture(game.sprite_menu, game.texture_menu, sfTrue);
    return (game);
}

game_t texture_sprite(game_t game, sfRenderWindow *window)
{
    game = create_texture(game);
    game = create_sprite(game);
    game = set_texture(game);
    if (!game.texture || !game.texture_bg || !window)
        exit(84);
    return (game);
}
