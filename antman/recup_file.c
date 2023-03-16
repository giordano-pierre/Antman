/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-nathan.baudelin
** File description:
** recup_file
*/
#include "../include/antman.h"

int verif_file (char *filepath)
{
    struct stat info;
    if (stat (filepath, &info) != 0) {
        write (1, "No such file !\n", 15);
        return -1;
    }
    if (S_ISREG(info.st_mode) == 0) {
        write (1, "Argument is not a file !\n", 25);
        return -1;
    }
    return 0;
}

char *open_file (char *filepath)
{
    char *buffer = NULL;
    int fp = open (filepath, O_RDONLY);
    if (fp == -1) {
        write (1, "Cannot open the file !\n", 23);
        return buffer;
    }
    struct stat info;
    stat (filepath, &info);
    buffer = malloc (sizeof(char) * (info.st_size + 1));
    if (read (fp, buffer, info.st_size) == -1) {
        write (1, "Cannot read the file !\n", 23);
        close (fp);
        return (buffer = NULL);
    }
    close (fp);
    if (info.st_size != 0)
        antman (buffer, info.st_size);
    return buffer;
}
