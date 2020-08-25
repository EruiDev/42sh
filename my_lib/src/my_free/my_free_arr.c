/*
** EPITECH PROJECT, 2020
** my_free_arr.c
** File description:
** my_free_arr.c
*/

#include "../../include/lib.h"

void my_free_arr(char **arr)
{
    int i = 0;
    int length = my_arrlen(arr);

    if (arr == NULL || length == 0)
        return;
    while (i < length) {
        if (arr[i] != NULL)
            free(arr[i]);
        i++;
    }
    if (arr != NULL)
        free(arr);
}