/*
** EPITECH PROJECT, 2020
** flag_separator.c
** File description:
** flag_separator.c
*/

#include "42sh.h"

int flag_separator(t_essential *essentials)
{
    env_flags *env_f = init_env_flags();
    char **env_sep = init_flags_separator();
    t_env_flags nb_flags = VERSION_FL;

    if (essentials->args[1] == NULL) {
        essentials = (*env_f[NORMAL_FL])(essentials);
        free_flags(env_f, env_sep);
        return (0);
    }
    while (env_sep[nb_flags] != NULL) {
        if (strcmp(env_sep[nb_flags], essentials->args[1]) == 0) {
            essentials = (*env_f[nb_flags])(essentials);
            free_flags(env_f, env_sep);
            return (1);
        }
        nb_flags++;
    }
    free_flags(env_f, env_sep);
    return (1);
}