/*
** EPITECH PROJECT, 2020
** History
** File description:
** save_history_on_file
*/

#include "42sh.h"

void save_history_on_file(char *command, char *time, int id)
{
    char *path = getenv("HOME");
    char *full_path = NULL;
    full_path = assembler(path, "/.42sh_history");
    FILE *fd = fopen(full_path, "a");
    char *id_str = int_to_str(id);

    fprintf(fd, "%s", id_str);
    fputs(" ", fd);
    fputs(time, fd);
    fputs(" ", fd);
    fputs(command, fd);
    fputs("\n", fd);
    fclose(fd);
    my_free_str(id_str);
}