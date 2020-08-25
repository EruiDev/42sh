/*
** EPITECH PROJECT, 2020
** env.c
** File description:
** env.c
*/

#include "42sh.h"

t_essential *env_cmd(t_essential *essentials)
{
    my_putarr(essentials->envp);
    return (essentials);
}