/*
** EPITECH PROJECT, 2020
** History
** File description:
** free_all_elements
*/

#include "42sh.h"

void delete_single_element(t_history *elements)
{
    if (elements->command != NULL)
        free(elements->command);
    if (elements->time != NULL)
        free(elements->time);
}

void delete_single_element_on_switch(t_history *elements)
{
    if (elements->command != NULL)
        free(elements->command);
    if (elements->time != NULL)
        free(elements->time);
    if (elements != NULL)
        free(elements);
    elements = NULL;
}

void free_all_elements(t_history *elements)
{
    t_history *tmp = elements;
    t_history *delete = NULL;

    while (tmp != NULL) {
        delete = tmp;
        tmp = tmp->next;
        delete_single_element_on_switch(delete);
    }
    elements = NULL;
}