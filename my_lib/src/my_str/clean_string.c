/*
** EPITECH PROJECT, 2020
** clean string
** File description:
** function to manage the program
*/

#include "../../include/lib.h"

char *remove_tabs(char *str)
{
    for (int i = 0; str[i] > '\0'; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    return (str);
}

int count(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == ' ' || str[i] == '\t')
            count++;
    }
    return (count);
}

int is_over(char *str, int i)
{
    for (; str[i] > '\0'; i++) {
        if (str[i] != ' ')
            return (0);
    }
    return (1);
}

char *clean(char *new, char *str)
{
    int e = 0;
    if (new == NULL)
        return (NULL);
    else if (count(str) == 0)
        return (str);
    str = remove_tabs(str);
    for (int i = 0; str[i] > '\0'; i++) {
        if (str[i] == ' ' && (str[i - 1] == ' ' || i == 0)) {
        } else if (is_over(str, i) == 1) {
            break;
        } else
            new[e++] = str[i];
    }
    new[e] = '\0';
    if (strlen(new) == count(new))
        return (NULL);
    return (new);
}

char *clean_string(char *str)
{
    char *new = malloc(sizeof(char) * (strlen(str) + 1));
    int i = 0;
    for (; str[i] != '\0' && str[i] == ' '; i++);
    new = clean(new, &str[i]);
    return (new);
}