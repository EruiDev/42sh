/*
** EPITECH PROJECT, 2020
** 42_env
** File description:
** function to modify an env variable
*/

#include "42sh.h"

char **change_env(char **env, char *var, char *new_param)
{
    int i = get_var(env, var);
    if (i == -1)
        return (env);
    char *temp = str_assembler(var, "=");
    char *new = str_assembler(temp, new_param);

    free(env[i]);
    env[i] = malloc(sizeof(char) * strlen(new));
    if (env[i] == NULL)
        exit(84);
    env[i] = strdup(new);
    if (env[i] == NULL)
        return (NULL);
    my_free_str(new);
    my_free_str(temp);
    my_free_str(new_param);
    return (env);
}