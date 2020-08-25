/*
** EPITECH PROJECT, 2020
** env_null.c
** File description:
** env_null.c
*/

#include "42sh.h"

t_essential *env_null(t_essential *essentials)
{
    int i = 0;

    if (essentials->args[1] == NULL)
        return (essentials);
    while (essentials->envp[i] != NULL) {
        my_putstr(essentials->envp[i]);
        i++;
    }
    return (essentials);
}