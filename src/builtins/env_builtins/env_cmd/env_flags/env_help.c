/*
** EPITECH PROJECT, 2020
** env_help.c
** File description:
** env_help.c
*/

#include "42sh.h"

t_essential *env_help(t_essential *essentials)
{
    my_putstr("Usage: env [OPTION]... [-] [NAME=VALUE]... \
            [COMMAND [ARG]...]\n");
    my_putstr("Set each NAME to VALUE in the environment and\
            run COMMAND.\n\n");
    my_putstr("Mandatory arguments to long options are \
            mandatory for short options too.\n");
    my_putstr("-0, --null           end each output line \
            with NUL, not newline\n");
    my_putstr("-u, --unset=NAME     remove variable from the environment\n");
    my_putstr("--help     display this help and exit\n");
    my_putstr("--version  output version information and exit\n\n");
    my_putstr("A mere - implies -i.  If no COMMAND, print the resulting \
            environment.\n\n");
    my_putstr("GNU coreutils online help: <http://www.gnu.\
            org/software/coreutils/>\n");
    my_putstr("Full documentation at: <http://www.gnu.\
            org/software/coreutils/env>\n");
    my_putstr("or available locally via: info '(coreutils) env invocation'\n");
    return (essentials);
}