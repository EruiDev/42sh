/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** checks
*/

#include "42sh.h"

int check_if_space(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (!isspace(str[i]))
            return (1);
    }
    return (0);
}

int check_arr(char **arr)
{
    int i = 0;

    while (arr[i] != NULL) {
        if (!check_if_space(arr[i])) {
            printf("Invalid null command.\n");
            return (-1);
        }
        i++;
    }
    return (0);
}