/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** cd
*/

#include "42sh.h"
#include "errno.h"

int error_cd(char *path)
{
    if (access(path, F_OK))
        printf("%s: No such file or directory.\n", path);
    else if (access(path, R_OK || W_OK || X_OK))
        printf("%s: Permission denied.\n", path);
    else
        return (0);
    return (1);
}

int cd_back(char *previous)
{
    if (previous == NULL || strcmp(previous, get_cwd()) == 0) {
        printf(": No such file or directory.\n");
        return (1);
    } else if (error_cd(previous) == 0) {
        chdir(previous);
        return (0);
    }
    return (1);
}

int cd_home(t_essential *essentials)
{
    char *user;
    char *home;
    char *path;

    user = get_usr(essentials);
    if (user == NULL) {
        printf(": No such file or directory.\n");
        return (0);
    }
    home = ("/home/\0");
    path = assembler(home, user);
    if (error_cd(path) == 0) {
        chdir(path);
        return (0);
    }
    return (1);
}

int cd_basic(char *path)
{
    if (error_cd(path) == 0) {
        chdir(path);
        return (0);
    }
    return (1);
}

int my_cd(t_essential *essentials)
{
    int status;
    char *previous = get_old_path(essentials->envp);
    essentials->envp = change_env(essentials->envp, strdup("OLDPWD"),
        get_cwd());
    if (my_arrlen(essentials->args) == 1 ||
        strcmp(essentials->args[1], "~") == 0)
        status = cd_home(essentials);
    else if (strcmp(essentials->args[1], "-") == 0)
        status = cd_back(previous);
    else
        status = cd_basic(essentials->args[1]);
    essentials->envp = change_env(essentials->envp, strdup("PWD"), get_cwd());
    essentials->status = status;
    return (status);
}
