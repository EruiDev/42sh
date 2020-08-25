/*
** EPITECH PROJECT, 2020
** my_add_str_to_arr.c
** File description:
** my_add_str_to_arr.c
*/

#include "../../include/lib.h"

char **my_add_str_to_arr(char **arr, char *str)
{
    int lenght = my_arrlen(arr) - 1;
    char **arr_cpy = my_arrdup(arr);
    char *str_cpy = strdup(str);
    char **new_arr = malloc(sizeof(char *) * (lenght + 2));

    if (arr == NULL || arr_cpy == NULL || str_cpy == NULL ||
    str == NULL || new_arr == NULL)
        return (NULL);
    for (int i = 0; i < lenght; i++) {
        new_arr[i] = strdup(arr_cpy[i]);
        if (new_arr[i] == NULL)
            return (NULL);
    }
    new_arr[lenght] = strdup(str_cpy);
    if (new_arr[lenght] == NULL)
        return (NULL);
    new_arr[lenght + 1] = NULL;
    my_free_arr(arr_cpy);
    my_free_str(str_cpy);
    return (new_arr);
}