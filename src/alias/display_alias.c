/*
** EPITECH PROJECT, 2020
** display_alias.c
** File description:
** display_alias.c
*/

#include "42sh.h"

void display_alias(t_alias *aliass)
{
    t_alias *tmp = aliass;
    int length = 0;
    char **command = NULL;

    while (tmp != NULL) {
        command = my_str_to_word_array(tmp->command);
        length = my_arrlen(command);
        if (length > 1)
            printf("%s\t(%s)\n", tmp->alias, tmp->command);
        else
            printf("%s\t%s\n", tmp->alias, tmp->command);
        tmp = tmp->next;
        my_free_arr(command);
    }
}