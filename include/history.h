/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** histoty
*/

#ifndef HISTOTY_H_
#define HISTOTY_H_
#include "42sh.h"

char const history_arguments[PARAMETER_LENGHT] = {
    'c',
    'h',
    'r',
    'S',
    'L',
    'M',
    'T',
    'A'
};

void (*history_arguments_deploy[4])(int nb, t_history *elements) = {
    arg_c,
    arg_h,
    arg_r,
    default_hst
};

#endif /* !HISTOTY_H_ */