/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_assembler
*/

#include "../../include/lib.h"

char *assembler(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int sn1 = strlen(s1);
    int sn2 = strlen(s2);
    char *final = malloc(sizeof(char) * ((sn1 + sn2) + 1));

    for (i = 0; s1[i] != '\0'; ++i)
        final[i] = s1[i];
    for (j = 0; s2[j] != '\0'; ++j, i++)
        final[i] = s2[j];
    final[i] = '\0';
    return (final);
}

char *str_assembler(char *str1, char *str2)
{
    char *new = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 2));
    if (new == NULL)
        return (NULL);
    strcpy(new, str1);
    strcat(new, str2);
    return (new);
}
