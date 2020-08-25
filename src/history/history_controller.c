/*
** EPITECH PROJECT, 2020
** History
** File description:
** history_contoller
*/

#include "42sh.h"
#include "history.h"

int check_display_help_case_norm_helper(char *args, int s)
{
    for (int t = 0; args[s] != history_arguments[t]; t++)
        if (t == PARAMETER_LENGHT) {
            printf(HISTORY_USAGE);
            return (-1);
        }
    return (0);
}

int history_argument_handler(char letter, char *nbr, t_history *elements)
{
    int nb = 0;
    int f = 0;

    (void)letter;
    nb = (nbr != NULL) ? my_getnbr(nbr) : -1;
    for (; letter != history_arguments[f]; f++);
    if (f >= 3)
        f = 3;
    (*history_arguments_deploy[f])(nb, elements);
    return (0);
}

void display_history_from_number(t_history *elements, char *nbr)
{
    int nb = (nbr != NULL) ? my_getnbr(nbr) : -1;
    int counter = 0;
    t_history *tmp = elements;

    while (tmp != NULL && nb != counter) {
        if (tmp->command != NULL)
            printf("%d\t%s  %s\n", tmp->id, tmp->time, tmp->command);
        counter++;
        tmp = tmp->next;
    }
}

int history_controller(t_essential *essentials)
{
    if (essentials->args[3] != NULL) {
        printf(HISTORY_MANY_ARGS);
        return (1);
    }
    for (int f = 1; essentials->args[f] != NULL; f++) {
        if (check_badly_formated(essentials->args[f]) == -1)
            return (1);
    } if (essentials->args[1] == NULL) {
        history_display(essentials->history);
        return (0);
    } if (essentials->args[1][0] == '-') {
        if (history_argument_handler(essentials->args[1][1],
        essentials->args[2], essentials->history) == -1)
            return (84);
    } else if (essentials->args[1][0] >= '0' &&
                essentials->args[1][0] <= '9') {
        display_history_from_number(essentials->history, essentials->args[1]);
    }
    return (0);
}