/*
** EPITECH PROJECT, 2020
** unalias.c
** File description:
** unalias.c
*/

#include "42sh.h"

void delete_alias(t_alias **alias, char *str)
{
    t_alias *temp = *alias, *prev;

    if (temp != NULL && (strcmp(temp->alias, str)) == 0) {
        *alias = temp->next;
        free(temp);
        return;
    } while (temp != NULL && (strcmp(temp->alias, str)) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

int unalias(t_essential *esnt)
{
    int i = 1;

    while (esnt->args[i] != NULL) {
        delete_alias(&esnt->alias, esnt->args[i]);
        i++;
    }
    return (0);
}