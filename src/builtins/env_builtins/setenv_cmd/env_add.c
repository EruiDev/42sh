/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_setenv functions
*/

#include "42sh.h"

char **env_add(char **env, char *name, char *arg)
{
    char *new;
    int i = get_var(env, name);
    if (i == -1) {
        new = str_assembler(name, "=");
        new = str_assembler(new, arg);
        return (add_env(env, new));
    } else if (env[i][strlen(env[i]) - 1] == '=') {
        new = str_assembler(env[i], arg);
        env[i] = malloc(sizeof(char) * strlen(new) + 1);
        if (env[i] == NULL)
            return (NULL);
        env[i] = strcpy(env[i], new);
    } else {
        new = str_assembler(env[i], ":");
        new = str_assembler(new, arg);
        env[i] = malloc(sizeof(char) * strlen(new) + 1);
        if (env[i] == NULL)
                return (NULL);
        env[i] = strcpy(env[i], new);
    }
    return (env);
}
