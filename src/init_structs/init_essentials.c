/*
** EPITECH PROJECT, 2020
** init_essentials.c
** File description:
** init_essentials.c
*/

#include "42sh.h"

t_essential *init_essentials(t_essential *essentials, char **envp)
{
    essentials->alias = NULL;
    essentials->history = init_history_element();
    essentials->args = NULL;
    essentials->envp = my_arrdup(envp);
    if (essentials->envp == NULL)
        return (NULL);
    essentials->status = 0;
    essentials->str = NULL;
    essentials->envp = change_env(essentials->envp, "OLDPWD", get_cwd());
    return (essentials);
}