/*
** EPITECH PROJECT, 2020
** History
** File description:
** check_and_delete_repeated
*/

#include "42sh.h"

void check_and_delete_repeated(t_history *elements, char *command)
{
    t_history *tmp = elements;
    t_history *save_previous = elements->next;

    while (tmp != NULL) {
        if (tmp->command == NULL);
        else if (strcmp(tmp->command, command) == 0) {
            save_previous->next = tmp->next;
            delete_single_element(tmp);
            return;
        }
        save_previous = tmp;
        tmp = tmp->next;
    }
}