/*
** EPITECH PROJECT, 2020
** getnextline.c
** File description:
** getnextline.c
*/

#include "../include/lib.h"

char *re_alloc(char *str)
{
    int pos = 0;
    char *str2 = malloc((strlen(str) + 2) * sizeof(char));

    if (str2 == NULL)
        return (NULL);
    while (str[pos] != '\0') {
        str2[pos] = str[pos];
        pos++;
    }
    str2[pos + 1] = '\0';
    my_free_str(str);
    return (str2);
}

char *get_next_line(const int fd)
{
    int pos = 0;
    int size = 0;
    static char temp[1];
    char *str = malloc(sizeof(char));
    str[0] = '\0';

    while ((size = read(fd, temp, 1)) > 0 && temp[0] != '\n') {
        str = re_alloc(str);
        if (str == NULL)
            return (NULL);
        str[pos] = temp[0];
        pos++;
    }
    if (size == 0 && pos == 0)
        return (NULL);
    else
        return (str);
}