/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019 [WSL: Ubuntu-18.04]
** File description:
** echo
*/

#include "42sh.h"

int echo_parsing(char **args)
{
    if (strcmp(args[1], "-n") == 0)
        return (1);
    return (0);
}

char **echo_setup(char **args, int is_newline)
{
    char **new = calloc(my_arrlen(args) + 2, sizeof(char *));
    int e = 2;
    new[0] = strdup(args[0]);
    if (is_newline == 1) {
        new[1] = strdup("-en");
        if (new[1] == NULL)
            return (NULL);
    } else {
        new[1] = strdup("-e");
        if (new[1] == NULL)
            return (NULL);
    }
    for (int i = 1 + is_newline; args[i] != NULL; i++, e++) {
        new[e] = strdup(args[i]);
        if (new[e] == NULL)
            return (NULL);
    }
    new[e] = NULL;
    return (new);
}

int my_echo(t_essential *essentials)
{
    int is_newline = echo_parsing(essentials->args);
    char **args = echo_setup(essentials->args, is_newline);
    pid_t pid = fork();
    if (!pid) {
        execvp(args[0], args);
    } else
        wait(NULL);
    my_free_arr(args);
    return (EXIT_SUCCESS);
}