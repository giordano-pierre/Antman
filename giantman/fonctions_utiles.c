/*
** EPITECH PROJECT, 2023
** antman_test
** File description:
** fonctions_utiles
*/
#include "../include/giantman.h"

int	my_getnbr_mid (char const *str, int *indice)
{
    int	nb = 0;
    int	signe = 1;
    while (str[*indice] == '+' || str[*indice] == '-'){
        if (str[*indice] == '-')
            signe = signe * (-1);
        *indice = *indice + 1;
    }
    while (str[*indice] != '\0'){
        if (str[*indice] >= '0' && str[*indice] <= '9'){
            nb = nb * 10;
            nb = nb + str[*indice] - '0';
            *indice = *indice + 1;
        } else
            return (nb * signe);
    }
    return (nb * signe);
}

void my_putchar(char c)
{
    write(1, &c , 1);
}
