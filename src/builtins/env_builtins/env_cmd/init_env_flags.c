/*
** EPITECH PROJECT, 2020
** init_env_flags.c
** File description:
** init_env_flags.c
*/

#include "42sh.h"

env_flags *init_env_flags(void)
{
    env_flags *env_f = malloc(sizeof(env_flags) * (NB_ENV + 1));

    if (env_f == NULL)
        return (NULL);
    env_f[VERSION_FL] = &env_version;
    env_f[O_FL] = &env_null;
    env_f[NULL_FL] = &env_null;
    env_f[U_FL] = &env_unset;
    env_f[UNSET_FL] = &env_unset;
    env_f[HELP_FL] = &env_help;
    env_f[NORMAL_FL] = &env_cmd;
    env_f[END_FL] = NULL;
    return (env_f);
}