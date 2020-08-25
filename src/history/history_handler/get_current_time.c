/*
** EPITECH PROJECT, 2020
** History
** File description:
** get_current_time
*/

#include "42sh.h"

char *reformat_time_structure(char *time)
{
    char *sender = malloc(sizeof(char) * 6);
    if (sender == NULL)
        return (NULL);
    int s = 0;

    for (int f = 11; f != 16; f++, s++)
        sender[s] = time[f];
    sender[s] = '\0';
    return (sender);
}

char *get_current_time(void)
{
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    char *final = NULL;

    final = reformat_time_structure(asctime(local));
    return (final);
}