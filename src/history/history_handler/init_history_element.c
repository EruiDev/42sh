/*
** EPITECH PROJECT, 2020
** history
** File description:
** init_history
*/

#include "42sh.h"

t_history *init_history_element(void)
{
    t_history *command = malloc(sizeof(t_history));

    if (command == NULL)
        return (NULL);
    command->command = NULL;
    command->time = NULL;
    command->id = 0;
    command->next = NULL;
    command->prev = NULL;
    return (command);
}