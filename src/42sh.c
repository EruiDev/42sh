/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** 42sh
*/

#include "42sh.h"

int shell(int ac, char **envp, char **av)
{
    int final_status = 0;
    t_essential *essentials = malloc(sizeof(t_essential));

    if (ac != 1) {
        printf("%s%s\n", av[1], ": No such file or directory.");
        return (1);
    }
    setbuf(stdout, NULL);
    if (essentials == NULL)
        return (84);
    essentials = init_essentials(essentials, envp);
    if (call_middleman(essentials) == -1)
        return (84);
    final_status = main_loop(essentials);
    essential_free(essentials);
    return (final_status);
}
