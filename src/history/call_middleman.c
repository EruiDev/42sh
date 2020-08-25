/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** call_middleman
*/

#include "42sh.h"

int call_middleman(t_essential *essentials)
{
    int fd = 0;
    char *path = getenv("HOME");
    char *full_path = NULL;

    full_path = assembler(path, "/.42sh_history");
    if (check_history_file() == -1)
        return (-1);
    fd = open(full_path, O_RDONLY);
    if ((grab_all_elements(essentials->history, fd)) == -1)
        return (-1);
    close(fd);
    return (0);
}