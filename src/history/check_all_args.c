/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** check_all_args
*/

#include "42sh.h"

void arg_h(int nb, t_history *elements)
{
    t_history *tmp = elements;
    int counter = 0;

    while (tmp != NULL && nb != counter) {
        if (tmp->command != NULL)
            printf("%s\n", tmp->command);
        tmp = tmp->next;
        counter++;
    }
}

void arg_r(int nb, t_history *elements)
{
    t_history *tmp = elements;
    int counter = 0;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    while (tmp != NULL && nb != counter) {
        if (tmp->command != NULL &&
        (!(tmp->command[0] >= '0' && tmp->command[0] <= '9')))
            printf("%d\t%s\t%s\n", tmp->id, tmp->time, tmp->command);
        tmp = tmp->prev;
        counter++;
    }
}

void arg_c(int nb, t_history *elements)
{
    char *path = getenv("HOME");
    char *full_path = NULL;
    full_path = assembler(path, "/.42sh_history");
    FILE *fd = fopen(full_path, "w");

    fd = fopen(full_path, "w");
    fprintf(fd, "0 %s start\n", get_current_time());
    (void)nb;
    (void)elements;
    fclose(fd);
}

void default_hst(int nb, t_history *elements)
{
    (void)elements;
    (void)nb;
    return;
}