/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../../include/lib.h"

int my_put_nbr(int nb)
{
    unsigned int new_nb;

    if (nb < 0) {
        my_putchar('-');
        new_nb = nb * -1;
    } else
        new_nb = nb;
    if (new_nb <= 9)
        my_putchar(new_nb + 48);
    else {
        my_put_nbr(new_nb / 10);
        my_put_nbr(new_nb % 10);
    }
    return (nb);
}