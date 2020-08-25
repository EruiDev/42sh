/*
** EPITECH PROJECT, 2020
** history
** File description:
** check_history_file
*/

#include "42sh.h"

int check_history_file(void)
{
    FILE *fd = NULL;
    char *path = getenv("HOME");
    char *full_path = NULL;

    full_path = assembler(path, "/.42sh_history");
    if (access(full_path, F_OK)) {
        fd = fopen(full_path, "w");
        fprintf(fd, "0 %s start\n", get_current_time());
        if (fd == NULL) {
            fclose(fd);
            return (-1);
        }
    }
    return (0);
}