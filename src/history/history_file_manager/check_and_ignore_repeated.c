/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** check_and_ignore_repeated
*/

#include "42sh.h"

int check_and_ignore_repeated(t_history *elements, char *command)
{
    t_history *tmp = elements;

    while (tmp != NULL) {
        if (strcmp(tmp->command, command) == 0) {
            return (-1);
        }
        tmp = tmp->next;
    }
    return (0);
}