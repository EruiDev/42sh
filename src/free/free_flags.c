/*
** EPITECH PROJECT, 2020
** free_flags.c
** File description:
** free_flags.c
*/

#include "42sh.h"

void free_flags(env_flags *env_f, char **env_sep)
{
    my_free_arr(env_sep);
    free(env_f);
}