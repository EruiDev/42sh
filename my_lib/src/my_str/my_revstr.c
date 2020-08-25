/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** my_revstr
*/

#include "../../include/lib.h"

char *my_revstr(char *str)
{
    int end = strlen(str)-1;
    int begin = 0;
    char temp;

    if (str == NULL)
        return (NULL);
    for (; begin < end; begin++, end--){
        temp = str[begin];
        str[begin] = str[end];
        str[end] = temp;
    }
    return (str);
}