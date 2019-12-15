/*
** EPITECH PROJECT, 2019
** int to str
** File description:
** int to array
*/

#include <stdlib.h>
#include <stdio.h>
#include "structure.h"

char *my_int_to_str(int nb)
{
    char *result;
    int nbr = 0;
    int count = 0;
    int temp = nb;
    int i = 0;
    int j = 0;

    if (nb < 0) {
        nb = -nb;
        count++;
    } result = malloc(sizeof(char) * (j + 1));
    for (i; nb / 10 != 0; i++) {
        nbr = nb % 10;
        result[i] = nbr + '0';
        nb /= 10;
    } result[i] = nb + '0';
    result[i + 1] = '\0';
    if (count == 1)
        result[i + 1] = '-';
    result = my_revstr(result);
    return (result);
}
