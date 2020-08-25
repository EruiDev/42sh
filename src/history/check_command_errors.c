/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** check_command_errors
*/

#include "42sh.h"

int check_display_help_case(char *args)
{
    for (int s = 1; args[s] != '\0'; s++) {
        if (check_display_help_case_norm_helper(args, s) == -1)
            return (-1);
    }
    return (0);
}

int check_display_bad_number_case(char *args)
{
    for (int s = 0; args[s] != '\0'; s++) {
        if (!(args[s] <= '9' && args[s] >= '0')) {
            printf(HISTORY_BAD_FORMED);
            return (-1);
        }
    }
    return (0);
}

int check_badly_formated(char *args)
{
    if (args[0] == '-') {
        if (check_display_help_case(args) == -1)
            return (-1);
    } else if (args[0] <= '9' && args[0] >= '0') {
        if (check_display_bad_number_case(args) == -1)
            return (-1);
    } else {
        printf(HISTORY_BAD_FORMED);
        return (-1);
    }
    return (0);
}