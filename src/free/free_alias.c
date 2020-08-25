/*
** EPITECH PROJECT, 2020
** free_alias.c
** File description:
** free_alias.c
*/

#include "42sh.h"

void free_alias(char *content, char *alias, char *command)
{
    my_free_str(content);
    my_free_str(alias);
    my_free_str(command);
}