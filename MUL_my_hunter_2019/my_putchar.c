/*
** EPITECH PROJECT, 2019
** my_putchar lib
** File description:
** library my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
