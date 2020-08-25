/*
** EPITECH PROJECT, 2020
** history
** File description:
** get_elements_from_file
*/

#include "42sh.h"

char *get_command(char *buffer)
{
    int f = 0;
    int s = 0;
    int t = 0;
    int c = 0;
    char *str = NULL;

    for (f = 0; buffer[f] != ' ' && buffer[f] != '\0'; f++);
    for (f++; buffer[f] != ' ' && buffer[f] != '\0'; f++);
    t = f + 1;
    for (f++; buffer[f] != '\0'; f++, s++);
    str = malloc(sizeof(char) * (s + 1));
    if (str == NULL)
        return (NULL);
    for (c = 0; buffer[t] != '\0'; t++, c++) {
        str[c] = buffer[t];
    }
    str[c] = '\0';
    return (str);
}

char *get_time(char *buffer)
{
    int f = 0;
    int s = 0;
    char *str = malloc(6);

    for (f = 0; buffer[f] != ' ' && buffer[f] != '\0'; f++);
    for (f++; buffer[f] != ' ' && buffer[f] != '\0'; f++, s++) {
        str[s] = buffer[f];
    }
    str[s] = '\0';
    return (str);
}

int check_buffer(char *buffer)
{
    int f = 0;
    int size = 0;

    for (f = 0; buffer[f] != ' '; f++) {
        if (!(buffer[f] >= '0' && buffer[f] <= '9'))
            return (-1);
    }
    for (f++; buffer[f] != ' '; f++, size++) {
        if (!(buffer[f] >= '0' && buffer[f] <= '9') && buffer[f] != ':') {
            return (-1);
        }
    }
    if (size != 5)
        return (-1);
    return (0);
}
