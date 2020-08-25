/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** TODO: add description
*/

#include "42sh.h"

char *get_cwd(void)
{
    char cwd[MAX_PATH];
    char *path;

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        path = strdup(cwd);
        if (path == NULL)
            return (NULL);
        return (path);
    }
    return (NULL);
}