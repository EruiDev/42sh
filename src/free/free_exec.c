/*
** EPITECH PROJECT, 2020
** free_exec.c
** File description:
** free_exec.c
*/

#include "42sh.h"

void free_exec(t_exec_info *exec)
{
    my_free_arr(exec->args);
    free(exec);
}