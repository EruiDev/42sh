/*
** EPITECH PROJECT, 2020
** my_str.h
** File description:
** my_str.h
*/

#ifndef MY_STR_H_
#define MY_STR_H_

char *my_revstr(char *str);
char **my_str_to_word_array(char *str);
char *clean_string(char *str);
char *assembler(char *s1, char *s2);
char *str_assembler(char *str1, char *str2);
char **my_str_to_arr(char *str, char delim);
int	my_strcnt(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *int_to_str(int num);
int my_str_is_alphanum(char *str);

#endif
