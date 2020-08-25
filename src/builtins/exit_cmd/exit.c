/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** arguments
*/

#include "42sh.h"

void exit_free(t_essential *essentials)
{
    my_free_arr(essentials->envp);
    my_free_arr(essentials->args);
    free_all_elements(essentials->history);
    free_linked_list(essentials->alias);
    free(essentials);
}

int my_exit(t_essential *essentials)
{
    int f = 0;
    int lenght = my_arrlen(essentials->args);

    if (lenght > 2) {
        my_putstr("exit: Expression Syntax.");
    }
    if (lenght == 2)
        f = my_getnbr(essentials->args[1]);
    exit_free(essentials);
    exit(f);
}