/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** path_parser
*/

#include "42sh.h"

int general_size(int f, char **envp)
{
    int counter = 0;

    for (int s = 5; envp[f][s] != '\0'; s++) {
        if (envp[f][s] == ':')
            counter++;
    }
    return (counter);
}

int specific_size(char *str, int s)
{
    int a = 0;

    for (; str[s] != ':' && str[s] != '\0'; s++, a++);
    return (a);
}

char **env_path(char **envp)
{
    char **args = NULL;
    int f = 0;
    int t = 0;

    for (f = 0; envp[f] != NULL && my_strcnt("PATH", envp[f]); f++);
    if (envp[f] == NULL)
        return (NULL);
    args = malloc(sizeof(char *) * (general_size(f, envp) + 2));
    args[t] = malloc((specific_size(envp[f], 5) + 1));
    for (int i = 0, s = 5; envp[f][s] != '\0'; s++, i++) {
        if (envp[f][s] == ':') {
            args[t][i] = '\0';
            i = -1;
            args[++t] = malloc((specific_size(envp[f], s) + 40));
        } else {
            args[t][i] = envp[f][s];
        }
    }
    args[t + 1] = NULL;
    return (args);
}

char *searcher(char *path, char *arg)
{
    struct dirent *entry;
    char *str = NULL;
    DIR *folder = opendir(path);

    if (folder == NULL)
        return (NULL);
    while ((entry = readdir(folder))) {
        if (strcmp(entry->d_name, arg) == 0) {
            str = assembler(path, arg);
            closedir(folder);
            return (str);
        }
    }
    closedir(folder);
    return (NULL);
}

char *get_path(char *array, char **envp)
{
    char *str = NULL;
    char **args = env_path(envp);

    if (args == NULL)
        return (NULL);
    for (int f = 0; args[f] != NULL; f++) {
        if ((str = searcher(assembler(args[f], "/"), array)) != NULL) {
            return (str);
        }
        free(str);
    }
    return (assembler("/bin/", array));
}