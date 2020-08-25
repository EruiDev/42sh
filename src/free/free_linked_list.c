/*
** EPITECH PROJECT, 2020
** free_linked_list.c
** File description:
** free_linked_list.c
*/

#include "42sh.h"

void free_linked_list(t_alias *aliass)
{
    t_alias *current = aliass;
    t_alias *next;

    while (current != NULL) {
        next = current->next;
        my_free_str(current->alias);
        my_free_str(current->command);
        free(current);
        current = next;
    }
    aliass = NULL;
}
