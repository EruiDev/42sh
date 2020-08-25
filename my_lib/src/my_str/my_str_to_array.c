/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_str_to_array
*/

#include "../../include/lib.h"

int count_to_char(char *str, char c)
{
    int i = 0;
    while (i < strlen(str)) {
        if (str[i] == c) {
            return (i);
        }
        i++;
    }
    return (i);
}

int count_chars(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count++;
    }
    return (count);
}

char **size_zero(char *str)
{
    char **arr = malloc(sizeof(char *) * 2);
    if (arr == NULL)
        return (NULL);
    arr[0] = str;
    arr[1] = NULL;
    return (arr);
}

char **my_str_to_arr(char *str, char delim)
{
    int count = count_to_char(str, delim);
    int spaces = count_chars(str, delim);
    int pos = 0, i = 0;
    char **arr;
    if (spaces == 0)
        return (size_zero(str));
    arr = malloc(sizeof(char *) * (strlen(str) * (spaces+1)));
    for (; i <= spaces; i++) {
        arr[i] = malloc(sizeof(char) * (count + 1));
        if (arr[i] == NULL || arr == NULL)
            return (NULL);
        strncpy(arr[i], &str[pos], count);
        arr[i][count] = '\0';
        pos += count + 1;
        if (pos < strlen(str))
            count = count_to_char(&str[pos], delim);
        else
            count = 0;
    }
    arr[i] = NULL;
    return (arr);
}