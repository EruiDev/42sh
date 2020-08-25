/*
** EPITECH PROJECT, 2020
** history
** File description:
** grab_all_elements
*/

#include "42sh.h"

void free_temporal_elements(char *buffer, char *temp_command, char *temp_time)
{
    my_free_str(temp_command);
    my_free_str(temp_time);
    my_free_str(buffer);
}

int set_first_elements(char *buffer, t_history *elements, int fd, int *id)
{
    char *temp_command = NULL;
    char *temp_time = NULL;

    if ((buffer = get_next_line(fd)) == NULL)
        return (0);
    if (check_buffer(buffer) != -1) {
        if ((temp_command = get_command(buffer)) == NULL)
            return (-1);
        if ((temp_time = get_time(buffer)) == NULL)
            return (-1);
        if ((elements->command = strdup(temp_command)) == NULL ||
        ((elements->time = strdup(temp_time)) == NULL))
            return (-1);
        elements->id = (*id)++;
        free_temporal_elements(buffer, temp_command, temp_time);
    }
    return (0);
}

int grab_all_elements(t_history *elements, int fd)
{
    char *buffer = NULL;
    int id = 0;
    char *temp_command = NULL, *temp_time = NULL;
    if (set_first_elements(buffer, elements, fd, &id) == -1)
        return (-1);
    while ((buffer = get_next_line(fd)) != NULL) {
        if (check_buffer(buffer) == -1) {
            my_free_str(buffer);
            continue;
        } else if ((temp_command = get_command(buffer)) == NULL) {
            my_free_str(buffer);
            return (-1);
        }
        if (check_and_ignore_repeated(elements, temp_command) == -1) {
            my_free_str(temp_command);
            continue;
        } else if ((temp_time = get_time(buffer)) == NULL)
            return (-1);
        add_element(elements, temp_command, temp_time, id++);
        free_temporal_elements(buffer, temp_command, temp_time);
    }
    return (0);
}