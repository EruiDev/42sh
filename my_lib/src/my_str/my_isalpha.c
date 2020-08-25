/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_isalpha
*/

#include "../../include/lib.h"

int my_isalpha(char *str)
{
    while (*str) {
        if (!((*str > 64 && *str < 91) || (*str > 96 && *str < 123)))
            return (0);
    ++str;
    }
    return (1);
}

int my_str_is_alphanum(char *str)
{
    while (*str) {
        if (*str == '_')
            str++;
        if (!isalnum(*str))
            return (0);
        ++str;
    }
    return (1);
}