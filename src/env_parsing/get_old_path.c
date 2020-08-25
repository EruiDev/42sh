/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** TODO: add description
*/

#include "42sh.h"

char *get_old_path(char **envp)
{
    int i = get_var(envp, "OLDPWD");
    if (i == -1)
        return (NULL);
    char *str = strdup(envp[i]);
    if (str == NULL)
        return (NULL);
    char **temp_arr = my_str_to_arr(str, '=');
    if (temp_arr == NULL)
        return (NULL);
    char *old_path = strdup(temp_arr[1]);
    if (old_path == NULL)
        return (NULL);

    my_free_str(str);
    my_free_arr(temp_arr);
    return (old_path);
}