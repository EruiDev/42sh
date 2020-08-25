/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** buildin
*/

#ifndef BUILDIN_H_
#define BUILDIN_H_
#define ARGNB 9
#include "42sh.h"

char const *buildin[ARGNB] = {
    "cd",
    "env",
    "exit",
    "setenv",
    "unsetenv",
    "alias",
    "unalias",
    "history",
    "none"
};

int (*arg_handler[ARGNB - 1])(t_essential *essentials) = {
    my_cd,
    flag_separator,
    my_exit,
    my_setenv,
    my_unsetenv,
    alias,
    unalias,
    history_controller
};

#endif /* !BUILDIN_H_ */