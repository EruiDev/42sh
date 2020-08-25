/*
** EPITECH PROJECT, 2020
** History
** File description:
** nbr_to_str
*/

#include "../../include/lib.h"

char *int_to_str(int num)
{
    char *str = NULL;
    int rem = 0;
    int len = 0;
    int n = num;

    while (n != 0){
        len++;
        n = n / 10;
    }
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    for (int i = 0; i < len; i++){
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    return (str);
}