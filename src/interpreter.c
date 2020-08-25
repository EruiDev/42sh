/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** interpreter
*/

#include "42sh.h"

void interpreter(t_essential *essentials)
{
    if (essentials->args[0] == NULL)
        return;
    if (executor(essentials->str, essentials) == 1) {
        essentials->status = 1;
        return;
    }
}