/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** main_loop
*/

#include "42sh.h"

void check_promt(t_essential *esnt)
{
    if (isatty(0) != 0)
        my_prompt(esnt->envp);
}

char *check_alias(char *str, t_essential *essential)
{
    t_alias *tmp = essential->alias;
    char **com = my_str_to_arr(str, ' ');
    int length = my_arrlen(com);

    while (tmp != NULL) {
        if (length == 1 && strcmp(tmp->alias, str) == 0) {
            my_free_arr(com);
            str = strdup(tmp->command);
        }
        if (length > 1 && strcmp(tmp->alias, com[0]) == 0) {
            my_free_str(com[0]);
            my_free_str(str);
            com[0] = strdup(tmp->command);
            str = get_command_back(com);
            my_free_arr(com);
        }
        tmp = tmp->next;
    }
    return (str);
}

int separator_split(t_essential *esnt)
{
    char **section = my_str_to_arr(esnt->str, ';');
    for (int i = 0; esnt->str[i] != '\0'; i++){
        if ((esnt->str[i] == '&' && esnt->str[i+1] == '&')
            || (esnt->str[i] == '|' && esnt->str[i+1] == '|')) {
            esnt->str[i] = ';';
            esnt->str[i+1] = ' ';
        }
    } if (section == NULL)
        exit(EXIT_FAILURE);
    for (int i = 0; section[i] != NULL; i++ ) {
        section[i] = check_alias(section[i], esnt);
        section[i] = clean_string(section[i]);
        if ((esnt->args = my_str_to_word_array(section[i])) == NULL) {
            my_free_str(esnt->str);
            return (84);
        }
        esnt->str = strdup(section[i]);
        if (esnt->str == NULL)
            return (1);
        interpreter(esnt);
        my_free_arr(esnt->args);
    }
    return (0);
}

int main_loop(t_essential *esnt)
{
    esnt->alias = get_alias();
    int i = 0;

    while (esnt->status != 84) {
        check_promt(esnt);
        if ((esnt->str = add_new_element_from_gnl(esnt->history)) == NULL)
            return (esnt->status);
        if (all_spaces(esnt->str) == 0)
            separator_split(esnt);
        i++;
    }
    return (esnt->status);
}
