/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** TODO: add description
*/

#include "42sh.h"

char *get_usr(t_essential *essentials)
{
    int usr_i = get_var(essentials->envp, strdup("LOGNAME"));
    char *usr = malloc(sizeof(char) * strlen(essentials->envp[usr_i]));

    if (usr == NULL || usr_i == -1)
        return (NULL);
    usr = strcpy(usr, &essentials->envp[usr_i][8]);
    if (usr == NULL)
        return (NULL);
    return (usr);
}