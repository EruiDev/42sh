/*
** EPITECH PROJECT, 2020
** get_full_command.c
** File description:
** get_full_command.c
*/

#include "42sh.h"

char *case_one(char *str, t_essential *esnt, int i, int length)
{
    str = strdup(esnt->args[i]);
    if (str == NULL)
        return (NULL);
    str = realloc(str, sizeof(char) * (length + i));
    if (str == NULL)
        return (NULL);
    return (str);
}

char *case_two(char *str, t_essential *esnt, int i, int length)
{
    str = realloc(str, sizeof(char) * (length + i));
    if (str == NULL)
        return (NULL);
    str = strcat(str, esnt->args[i]);
    if (str == NULL)
        return (NULL);
    return (str);
}

char *get_full_command(t_essential *essential)
{
    int length = 0;
    char *str = NULL;

    for (int i = 2; essential->args[i] != NULL; i++) {
        length += strlen(essential->args[i]);
        if (i == 2) {
            str = case_one(str, essential, i, length);
            if (str == NULL)
                return (NULL);
        } else {
            str = case_two(str, essential, i, length);
            if (str == NULL)
                return (NULL);
        } if (essential->args[i + 1] != NULL) {
            str = strcat(str, " ");
            if (str == NULL)
                return (NULL);
        }
    }
    return (str);
}