/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** TODO: add description
*/

#include "42sh.h"

int get_var(char **envp, char *var)
{
    for (int i = 0; envp[i] != NULL; i++) {
        if (strncmp(var, envp[i], strlen(var)) == 0) {
            return (i);
        }
    }
    return (-1);
}