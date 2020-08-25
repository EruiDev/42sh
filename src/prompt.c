/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** main_loop
*/

#include "42sh.h"

void my_username(char **env)
{
    int i = get_var(env, "USER");
    char **tmp = my_str_to_arr(env[i], '=');

    printf("%s", tmp[1]);
    free(tmp);
}

char *my_pwd(char **env)
{
    (void)env;
    char *cwd = getcwd(NULL, 0);
    if (cwd != NULL) {
        return (cwd);
    }
    return (NULL);
}

void my_prompt(char **env)
{
    my_username(env);
    printf(":");
    char *pwd_str = my_pwd(env);
    printf("%s", pwd_str);
    printf(" -> ");
    free(pwd_str);
}

int all_spaces(char *str)
{
    int count = 0;
    int len = strlen(str);
    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] == ' ')
            count++;
    }
    if (count == len)
        return (1);
    return (0);
}