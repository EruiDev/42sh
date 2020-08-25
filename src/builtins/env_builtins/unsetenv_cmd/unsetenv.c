/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** unsetenv related functions
*/

#include "42sh.h"

char **env_rm(char **env, char *name)
{
    char **new_env = malloc(sizeof(char*) * (my_arrlen(env)));
    int i = 0;
    int new_i = 0;
    int exclude = get_var(env, name);

    if (exclude < 0)
        return (env);
    else if (new_env == NULL)
        return (NULL);
    while (env[i] != NULL) {
        if (i != exclude)
            new_env[new_i++] = strdup(env[i]);
        i++;
    }
    new_env[i - 1] = NULL;
    my_free_arr(env);
    return (new_env);
}

int my_unsetenv(t_essential *param)
{
    if (my_arrlen(param->args) == 1)
        printf("unsetenv: Too few arguments.\n");
    for (int i = 0; param->args[i] != NULL; i++)
        param->envp = env_rm(param->envp, param->args[i]);
    return (0);
}
