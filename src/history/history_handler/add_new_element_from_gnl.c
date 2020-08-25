/*
** EPITECH PROJECT, 2020
** History
** File description:
** add_new_element_from_gnl
*/

#include "42sh.h"

char *add_new_element_from_gnl(t_history *elements)
{
    char *gnl = NULL;
    char *time = get_current_time();
    int id = get_last_id(elements) + 1;

    if ((gnl = get_next_line(0)) == NULL)
        return (NULL);
    check_and_delete_repeated(elements, gnl);
    add_element(elements, gnl, time, id);
    save_history_on_file(gnl, time, id);
    return (gnl);
}