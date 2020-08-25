/*
** EPITECH PROJECT, 2020
** init_exec_info.c
** File description:
** init_exec_info.c
*/

#include "42sh.h"

t_exec_info *init_exec_info(void)
{
    t_exec_info *info = malloc(sizeof(t_exec_info));

    if (info == NULL)
        return (NULL);
    info->n = 0;
    info->first = 1;
    info->input = 0;
    info->status = 0;
    return (info);
}