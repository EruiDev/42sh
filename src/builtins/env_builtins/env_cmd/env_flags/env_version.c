/*
** EPITECH PROJECT, 2020
** env_version.c
** File description:
** env_version.c
*/

#include "42sh.h"

t_essential *env_version(t_essential *essentials)
{
    my_putstr("env (GNU coreutils) 8.28\n");
    my_putstr("Copyright (C) 2017 Free Software Foundation, Inc.\n");
    my_putstr("License GPLv3+: GNU GPL version 3 or later\
<http://gnu.org/licenses/gpl.html>.\n");
    my_putstr("This is free software: you are free to change and\
redistribute it.\n");
    my_putstr("There is NO WARRANTY, to the extent permitted by law.\n\n");
    my_putstr("Written by Richard Mlynarik and David MacKenzie.\n");
    return (essentials);
}