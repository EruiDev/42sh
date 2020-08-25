/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr
*/

#include "../../include/lib.h"

void my_putstr(char const *str)
{
    int x = 0;

    if (str == NULL)
        return;
    for (x = 0 ; str[x] != '\0' ; x++)
        my_putchar(str[x]);
}
