/*
** EPITECH PROJECT, 2020
** my_putarr.c
** File description:
** my_putarr.c
*/

#include "../../include/lib.h"

void my_putarr(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return;
    while (arr[i] != NULL) {
        my_putstr(arr[i]);
        my_putchar('\n');
        i++;
    }
}