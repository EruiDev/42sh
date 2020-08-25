/*
** EPITECH PROJECT, 2020
** my_free_str.c
** File description:
** my_free_str.c
*/

#include "../../include/lib.h"

void my_free_str(char *str)
{
    if (str != NULL)
        free(str);
}