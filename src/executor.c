/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** executor
*/

#include "42sh.h"
#include "buildin.h"
#include <errno.h>

int get_exec(char **args)
{
    for (int i = 0; i < ARGNB; i++) {
        if (strcmp(buildin[i], args[0]) == 0) {
            return (i);
        }
    }
    return (ARGNB);
}

int check_exec(t_exec_info *exec_info)
{
    if (exec_info->status == -1 && errno == 2) {
        printf("%s: Command not found\n", exec_info->args[0]);
        exit(1);
    }
    if (exec_info->status == -1)
        exit(1);
    return (0);
}

int multi_pipe_exec(int first, int last, t_exec_info *exec_info)
{
    int pipes_fd[2];
    pipe(pipes_fd);
    exec_info->pid = fork();
    if (exec_info->pid == 0){
        if (first == 1 && last == 0 && exec_info->input == 0)
            dup2(pipes_fd[1], 1);
        else if (first == 0 && last == 0 && exec_info->input != 0){
            dup2(exec_info->input, 0);
            dup2(pipes_fd[1], 1);
        } else
            dup2(exec_info->input, 0);
        exec_info->status = execvp(exec_info->args[0], exec_info->args);
        check_exec(exec_info);
    }
    if (exec_info->input != 0)
        close(exec_info->input);
    close(pipes_fd[1]);
    if (last == 1)
        close(pipes_fd[0]);
    return (pipes_fd[0]);
}

int my_exec(char *cmd, int last, t_exec_info *exec_info,
    t_essential *essentials)
{
    int status;
    cmd = clean_string(cmd);
    if (cmd == NULL)
        return (1);
    exec_info->args = my_str_to_arr(cmd, ' ');
    if (exec_info->args == NULL)
        return (1);
    exec_info->arg_num = get_exec(exec_info->args);
    if (exec_info->args[0] != NULL) {
        if (exec_info->arg_num != ARGNB)
            status = (*arg_handler[exec_info->arg_num])(essentials);
        else {
            exec_info->n = exec_info->n + 1;
            status = multi_pipe_exec(exec_info->first, last, exec_info);
        }
        return (status);
    }
    return (0);
}

int executor(char *str, t_essential *essentials)
{
    t_exec_info *info = init_exec_info();
    int i = 0;
    char **arr_of_cmd = my_str_to_arr(str, '|');

    if (check_arr(arr_of_cmd) == -1)
        return (1);
    for (i = 0; arr_of_cmd[i + 1] != NULL; i++) {
        info->input = my_exec(arr_of_cmd[i], 0, info, essentials);
        info->first = 0;
    }
    info->input = my_exec(arr_of_cmd[i], 1, info, essentials);
    for (int e = 0; e < info->n ; e++) {
        wait(NULL);
    }
    free_exec(info);
    return (0);
}