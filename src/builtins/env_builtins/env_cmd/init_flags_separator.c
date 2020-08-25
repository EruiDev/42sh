/*
** EPITECH PROJECT, 2020
** init_flags_separator.c
** File description:
** init_flags_separator.c
*/

#include "42sh.h"

char **init_flags_separator(void)
{
    char **flag_sep = malloc(sizeof(char *) * (NB_ENV + 4));
    int i = 0;

    flag_sep[VERSION_FL] = strdup(VERSION_F);
    flag_sep[O_FL] = strdup(NULL_FO);
    flag_sep[NULL_FL] = strdup(NULL_FT);
    flag_sep[U_FL] = strdup(UNSET_FO);
    flag_sep[UNSET_FL] = strdup(UNSET_FT);
    flag_sep[HELP_FL] = strdup(HELP_F);
    flag_sep[NORMAL_FL] = strdup(NORMAL_F);
    flag_sep[END_FL] = NULL;
    while (i < NB_ENV) {
        if (flag_sep[i] == NULL)
            return (NULL);
        i++;
    }
    return (flag_sep);
}