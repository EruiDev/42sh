/*
** EPITECH PROJECT, 2020
** files.h
** File description:
** files.h
*/

#ifndef FILES_H_
#define FILES_H_
#include "42sh.h"

//functions from builtins
    //cd_cmd
int my_cd(t_essential *essentials);
    //env_builtins
        //env_cmd
int flag_separator(t_essential *essentials);
env_flags *init_env_flags(void);
char **init_flags_separator(void);
t_essential *env_help(t_essential *essentials);
t_essential *env_null(t_essential *essentials);
t_essential *env_unset(t_essential *essentials);
t_essential *env_version(t_essential *essentials);
t_essential *env_cmd(t_essential *essentials);
        //setenv_cmd
int my_setenv(t_essential *param);
int check_setenv(char **args);
char **add_env(char **env, char *new_param);
char **change_env(char **env, char *var, char *new_param);
char **env_add(char **env, char *name, char *arg);

        //unsetenv_cmd
int my_unsetenv(t_essential *param);
    //exit_cmd
int my_exit(t_essential *essentials);
    //echo_cmd
int my_echo(t_essential *essentials);

//functions from main_loop.c
int main_loop(t_essential *essentials);

//functions from interpreter.c
void interpreter(t_essential *essentials);

//functions from 42sh
int shell(int ac, char **envp, char **av);

//functions from executor
int executor(char *str, t_essential *essentials);
int check_arr(char **arr);

//functions from path_parser
char *get_path(char *array, char **envp);

//functions from env_parsing
int get_var(char **envp, char *var);
char *get_usr(t_essential *essentials);
char *get_cwd(void);
char *get_old_path(char **envp);

//functions from arg_check
int check_args(char *str);

void my_prompt(char **env);

int all_spaces(char *str);

//functions from free
void free_flags(env_flags *env_f, char **env_sep);
void essential_free(t_essential *essentials);
void free_linked_list(t_alias *aliass);
void free_alias(char *content, char *alias, char *command);
void free_exec(t_exec_info *exec);

//functions from init_struct
t_essential *init_essentials(t_essential *essentials, char **envp);
t_exec_info *init_exec_info(void);
t_alias *init_alias_linked(char *alias, char *command);

void create_new_alias(char *alias, char *command, t_alias *aliass);
void display_alias(t_alias *aliass);
//alias
t_alias *get_alias(void);
char *get_command_file(char *str);
char *get_alias_file(char *str);
int alias(t_essential *essential);
int unalias(t_essential *esnt);
char *get_full_command(t_essential *essential);
int check_if_exist(t_essential *essential);
char *get_command_back(char **com);

//functions for call
void default_hst(int nb, t_history *elements);
void arg_c(int nb, t_history *elements);
void arg_r(int nb, t_history *elements);
void arg_h(int nb, t_history *elements);
int check_display_help_case_norm_helper(char *args, int s);

//all functions from history
void history_display(t_history *element);
int add_element(t_history *history, char *command, char *time, int id);
char *get_current_time();
char *get_command(char *buffer);
void save_history_on_file(char *command, char *time, int id);
void check_and_delete_repeated(t_history *elements, char *command);
t_history *init_history_element();
int get_last_id(t_history *elements);
void free_all_elements(t_history *elements);
void delete_single_element(t_history *elements);
int grab_all_elements(t_history *elements, int fd);
char *add_new_element_from_gnl(t_history *elements);
int check_and_ignore_repeated(t_history *elements, char *command);
int check_history_file();
int call_middleman(t_essential *essentials);
int check_buffer(char *buffer);
int check_badly_formated(char *args);
char *get_time(char *buffer);
int history_controller(t_essential *essentials);
void add_element_on_first_position(t_history *history, char *command,
    char *time, int id);

#endif
