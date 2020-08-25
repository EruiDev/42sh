/*
** EPITECH PROJECT, 2020
** history
** File description:
** history_display
*/

#include "42sh.h"

void history_display(t_history *element)
{
    t_history *tmp = element;

    while (tmp != NULL) {
        if (tmp->command != NULL)
            printf("%d\t%s  %s\n", tmp->id, tmp->time, tmp->command);
        tmp = tmp->next;
    }
}