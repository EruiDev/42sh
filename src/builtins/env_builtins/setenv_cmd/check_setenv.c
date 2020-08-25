/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_setenv functions
*/

#include "42sh.h"

int check_setenv(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        if (!my_str_is_alphanum(args[i])) {
            my_putstr("setenv: Variable name must contain alphanumeric"
                      " characters.\n");
            return (-1);
        } else if (!isalpha(args[1][0]) && args[1][0] != '_') {
            my_putstr("setenv: Variable name must begin with a letter.\n");
            return (-1);
        }
    }
    return (0);
}