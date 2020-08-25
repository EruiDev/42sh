/*
** EPITECH PROJECT, 2020
** history
** File description:
** history_add_element
*/

#include "42sh.h"

int add_element(t_history *history, char *command, char *time, int id)
{
    t_history *new_element = init_history_element();
    t_history *tmp = history;

    if (new_element == NULL)
        return (84);
    if ((new_element->command = strdup(command)) == NULL)
        return (84);
    if ((new_element->time = strdup(time)) == NULL)
        return (84);
    new_element->id = id;
    while (tmp->next != NULL)
        tmp = tmp->next;
    new_element->prev = tmp;
    tmp->next = new_element;
    return (0);
}