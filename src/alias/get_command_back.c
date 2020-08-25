/*
** EPITECH PROJECT, 2020
** get_command_back.c
** File description:
** get_command_back.c
*/

#include "42sh.h"

char *case_one_t(char *str, char **com, int i, int length)
{
    str = strdup(com[i]);
    if (str == NULL)
        return (NULL);
    str = realloc(str, sizeof(char) * (length + 2));
    if (str == NULL)
        return (NULL);
    return (str);
}

char *case_two_t(char *str, char **com, int i, int length)
{
    str = realloc(str, sizeof(char) * (length + i + 2));
    if (str == NULL)
        return (NULL);
    str = strcat(str, com[i]);
    if (str == NULL)
        return (NULL);
    return (str);
}

char *get_command_back(char **com)
{
    int length = 0;
    char *str = NULL;

    for (int i = 0; com[i] != NULL; i++) {
        length += strlen(com[i]);
        if (i == 0) {
            str = case_one_t(str, com, i, length);
            if (str == NULL)
                return (NULL);
        } else {
            str = case_two_t(str, com, i, length);
            if (str == NULL)
                return (NULL);
        } if (com[i + 1] != NULL) {
            str = strcat(str, " ");
            if (str == NULL)
                return (NULL);
        }
    }
    return (str);
}