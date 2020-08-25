/*
** EPITECH PROJECT, 2020
** alias.c
** File description:
** alias.c
*/

#include "42sh.h"

int check_lengths(t_essential **esnt, int length)
{
    if (length > 3)
        (*esnt)->args[2] = get_full_command(*esnt);
    else if (length == 1) {
        display_alias((*esnt)->alias);
        return (0);
    }
    return (1);
}

int alias(t_essential *essential)
{
    int length = my_arrlen(essential->args);
    int i = check_lengths(&essential, length);

    if (i == 0 || length == 2)
        return (0);
    i = check_if_exist(essential);
    return (i);
}