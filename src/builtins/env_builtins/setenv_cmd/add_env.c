/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_setenv functions
*/

#include "42sh.h"

char **add_env(char **env, char *new_param)
{
    char **new_env = malloc(sizeof(char*) * (my_arrlen(env) + 2));
    int i = 0;

    if (new_env == NULL)
        return (NULL);
    while (env[i] != NULL) {
        new_env[i] = strdup(env[i]);
        if (new_env[i] == NULL)
            return (NULL);
        i++;
    }
    new_env[i] = strdup(new_param);
    if (new_env[i] == NULL)
        return (NULL);
    new_env[i + 1] = NULL;
    my_free_arr(env);
    my_free_str(new_param);
    return (new_env);
}
