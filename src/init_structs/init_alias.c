/*
** EPITECH PROJECT, 2020
** init_alias.c
** File description:
** init_alias.c
*/

#include "42sh.h"

t_alias *init_alias_linked(char *alias, char *command)
{
    t_alias *aliass = malloc(sizeof(t_alias));

    if (aliass == NULL)
        return (NULL);
    aliass->alias = strdup(alias);
    aliass->command = strdup(command);
    aliass->next = NULL;
    if (aliass->alias == NULL || aliass->command == NULL)
        return (NULL);
    return (aliass);
}

void create_new_alias(char *alias, char *command, t_alias *aliass)
{
    t_alias *tmp = aliass;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = init_alias_linked(alias, command);
}