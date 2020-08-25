/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_strcnt
*/

#include "../../include/lib.h"

int	my_strcnt(char const *s1, char const *s2)
{
    int f = 0;

    for (; (s1[f] == s2[f]) && (s2[f + 1] != '=') && (s1[f] != '\0'); f++);
    return (s1[f] - s2[f]);
}
