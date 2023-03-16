/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** fonctions_utiles
*/
#include "../include/antman.h"

void my_putchar(char c)
{
    write(1, &c , 1);
}

int my_strlen (char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        i = i + 1;
    }
    return i;
}

void my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

void my_put_nbr(int nb)
{
    int nina = 1;
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb >= 0) {
        if (nb >= 10) {
            nina = (nb % 10);
            nb = (nb - nina) / 10;
            my_put_nbr(nb);
            my_putchar(48 + nina);
        } else {
            my_putchar(48 + nb % 10);
        }
    }
}
