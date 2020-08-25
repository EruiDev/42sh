/*
** EPITECH PROJECT, 2020
** check_exist_alias.c
** File description:
** check_exist_alias.c
*/

#include "42sh.h"

void if_exist(t_essential **essential)
{
    t_alias *tmp = (*essential)->alias;

    while (tmp != NULL) {
        if (strcmp(tmp->alias, (*essential)->args[1]) == 0) {
            my_free_str(tmp->command);
            tmp->command = strdup((*essential)->args[2]);
        }
        tmp = tmp->next;
    }
}

int check_if_exist(t_essential *essential)
{
    t_alias *tmp = essential->alias;

    while (tmp != NULL) {
        if (strcmp(tmp->alias, essential->args[1]) == 0) {
            if_exist(&essential);
            return (0);
        }
        tmp = tmp->next;
    }
    create_new_alias(essential->args[1], essential->args[2], essential->alias);
    return (0);
}