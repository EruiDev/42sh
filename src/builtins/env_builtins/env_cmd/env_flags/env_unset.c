/*
** EPITECH PROJECT, 2020
** env_unset.c
** File description:
** env_unset.c
*/

#include "42sh.h"

t_essential *env_unset(t_essential *essentials)
{
    char *str = my_strcat("unsetenv ", essentials->args[2]);
    char *input = my_strcat(str, "\0");
    my_free_str(str);
    my_free_arr(essentials->args);
    essentials->args = my_str_to_word_array(input);
    my_free_str(input);
    int i = my_unsetenv(essentials);
    (void)i;
    return (essentials);
}