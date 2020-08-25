/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "../../include/lib.h"

char *my_strcat(char *dest, char const *src)
{
    int length_s = strlen(src);
    int length_d = strlen(dest);
    int total_length = length_d + length_s + 1;
    char *fin = malloc(sizeof(char) * (total_length + 2));
    int i = 0;
    int x = 0;

    if (dest == NULL || src == NULL || fin == NULL)
        return (NULL);
    for (i; i < length_d; i++)
        fin[i] = dest[i];
    for (i; i < total_length; i++, x++)
        fin[i] = src[x];
    fin[total_length] = '\0';
    return (fin);
}
