/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_
#include "42sh.h"

typedef struct s_history {
    int id;
    char *time;
    char *command;
    struct s_history *next;
    struct s_history *prev;
} t_history;

typedef struct s_alias {
    char *alias;
    char *command;
    struct s_alias *next;
} t_alias;

typedef struct s_essentials {
    char **envp;
    char **args;
    char *str;
    char *previous_path;
    int status;
    t_alias *alias;
    t_history *history;
} t_essential;

typedef struct exec_info {
    char **args;
    pid_t pid;
    int command_pipe[2];
    char *line;
    int n;
    int input;
    int first;
    int status;
    int arg_num;
}t_exec_info;

typedef enum s_env_flags
{
    VERSION_FL = 0,
    O_FL,
    NULL_FL,
    U_FL,
    UNSET_FL,
    HELP_FL,
    NORMAL_FL,
    END_FL
}t_env_flags;

typedef t_essential *(*env_flags)(t_essential*);

#endif
