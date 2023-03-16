/*
** EPITECH PROJECT, 2023
** antman_test
** File description:
** bin
*/
#include "../include/giantman.h"

int get_start (char *file, int size_leaf)
{
    int ind = 1;
    int count = 0;
    while (count < size_leaf) {
        if (file[ind] == '@' && file[ind - 1] != '@')
            count++;
        ind++;
    }
    return ind;
}

char *dec_to_bin (int c)
{
    char *temp = malloc (sizeof(char) * 9);
    for (int r = 0; r < 8; r++)
        temp[r] = '0';
    temp[8] = '\0';
    for (int i = 7; i >= 0; i--) {
        if ((c % 2) == 1)
            temp[i] = '1';
        c = c / 2;
    }
    return temp;
}

char *create_bin (char *file, unsigned int size, int start)
{
    unsigned int nb = size - start;
    char *bin = malloc (sizeof(char) * (nb * 8 + 1));
    unsigned int ind = 0;
    int car;
    char *temp;
    for (unsigned int i = start; i < size; i++) {
        car = (int) file[i];
        if (car < 0)
            car = 256 + car;
        temp = dec_to_bin (car);
        for (int j = 0; j < 8; j++) {
            bin[ind] = temp[j];
            ind = ind + 1;
        }
        free (temp);
    }
    bin[ind] = '\0';
    return bin;
}
