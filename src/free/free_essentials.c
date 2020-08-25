/*
** EPITECH PROJECT, 2020
** free_essentials.c
** File description:
** free_essentials.c
*/

#include "42sh.h"

void essential_free(t_essential *essentials)
{
    free_all_elements(essentials->history);
    my_free_arr(essentials->envp);
    free(essentials);
}