/*
** EPITECH PROJECT, 2020
** get_alias.c
** File description:
** get_alias.c
*/

#include "42sh.h"

char *get_alias_file(char *str)
{
    int i = 0;
    int j = 0;
    int size = 0;
    char *alias = NULL;

    for (; str[i] != '='; i++)
        size = i;
    alias = malloc(sizeof(char) * (size - 4));
    for (i = 6; i <= size; i++, j++)
        alias[j] = str[i];
    alias[j] = '\0';
    return (alias);
}