/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_setenv functions
*/

#include "42sh.h"

char **env_no_args(char **env, char *name, char *arg)
{
    (void)name;
    (void)arg;
    my_putarr(env);
    return (env);
}

char **env_one_arg(char **env, char *name, char *arg)
{
    (void)arg;
    env = add_env(env, str_assembler(name, "="));
    if (env == NULL)
        return (NULL);
    return (env);
}

char **env_two_args(char **env, char *name, char *arg)
{
    env = env_add(env, name, arg);
    if (env == NULL)
        return (NULL);
    return (env);
}

char **(*env_launch[3])(char **env, char *name, char *arg) = {
    env_no_args,
    env_one_arg,
    env_two_args
};

char **args_prep(char **args, int len)
{
    if (len == 1) {
        args[1] = NULL;
        args[2] = NULL;
    } else if (len == 2)
        args[2] = NULL;
    return (args);
}

int my_setenv(t_essential *param)
{
    int len = my_arrlen(param->args);
    if (len == 1) {
        param->envp = env_no_args(param->envp, NULL, NULL);
        return (0);
    }else if (check_setenv(param->args))
        return (-1);
    param->envp = (*env_launch[len - 1])(param->envp, param->args[1],
        param->args[2]);
    if (param->envp == NULL)
        exit(84);
    return (0);
}