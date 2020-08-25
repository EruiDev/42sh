/*
** EPITECH PROJECT, 2020
** get_alias_file.c
** File description:
** get_alias_file.c
*/

#include "42sh.h"

t_alias *get_alias(void)
{
    int fd = open(".42shrc", O_RDONLY);
    if (fd == -1)
        return (NULL);
    char *content = get_next_line(fd);
    char *alias = get_alias_file(content);
    char *command = get_command_file(content);
    t_alias *aliass = init_alias_linked(alias, command);

    while (content != NULL) {
        free_alias(content, alias, command);
        content = get_next_line(fd);
        if (content != NULL) {
            alias = get_alias_file(content);
            command = get_command_file(content);
            create_new_alias(alias, command, aliass);
        }
    }
    close(fd);
    return (aliass);
}