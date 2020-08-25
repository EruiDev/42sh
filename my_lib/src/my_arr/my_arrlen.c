/*
** EPITECH PROJECT, 2020
** mesure.c
** File description:
** mesure.c
*/

#include "../../include/lib.h"

int my_arrlen(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return (0);
    while (arr[i] != NULL)
        i++;
    return (i);
}