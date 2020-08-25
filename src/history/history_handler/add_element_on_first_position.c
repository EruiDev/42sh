/*
** EPITECH PROJECT, 2020
** History
** File description:
** add_element_on_first_position
*/

#include "42sh.h"

void add_element_on_first_position(t_history *element, char *command,
    char *time, int id)
{
    element->command = strdup(command);
    if (element->command == NULL)
        return;
    element->time = strdup(time);
    if (element->time == NULL)
        return;
    element->id = id;
}