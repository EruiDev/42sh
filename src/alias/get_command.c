/*
** EPITECH PROJECT, 2020
** get_command.c
** File description:
** get_command.c
*/

#include "42sh.h"

char *get_command_file(char *str)
{
    int i = 0;
    int j = 0;
    int size = 0;
    int end = strlen(str) - 1;
    char *command = NULL;

    for (; str[i] != '='; i++)
        size = i;
    command = malloc(sizeof(char) * (end - size));
    for (i = size + 3; i < end; i++, j++)
        command[j] = str[i];
    command[j] = '\0';
    return (command);
}