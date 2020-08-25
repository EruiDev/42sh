/*
** EPITECH PROJECT, 2020
** str_to_word_array.c
** File description:
** str_to_word_array.c
*/

#include "../../include/lib.h"

int my_count(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0'){
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        if (str[i])
            count++;
        if (str[i] != '\0')
            i++;
    }
    return (count);
}

int my_strlentab(const char *str)
{
    int i = -1;

    while (str[++i] != '\0' && str[i] != ' ' && str[i] != '\t');
    return (i);
}

char **my_str_to_word_array(char *str)
{
    char **tab;
    int i = 0;
    int z = -1;

    if ((tab = malloc((my_count(str) + 1) * sizeof(*tab))) == NULL)
        return (NULL);
    while (str[i]){
        int j = 0;
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            ++i;
        if ((tab[++z] = malloc((my_strlentab(&str[i]) + 1)
            * sizeof(**tab))) == NULL)
            return (NULL);
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            tab[z][j++] = str[i++];
        tab[z][j] = '\0';
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            ++i;
    } tab[z + 1] = '\0';
    return (tab);
}