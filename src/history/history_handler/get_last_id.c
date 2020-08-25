/*
** EPITECH PROJECT, 2020
** History
** File description:
** get_last_id
*/

#include "42sh.h"

int get_last_id(t_history *elements)
{
    t_history *tmp = elements;

    while (tmp->next != NULL)
        tmp = tmp->next;
    if (tmp != NULL)
        return (tmp->id);
    return (0);
}