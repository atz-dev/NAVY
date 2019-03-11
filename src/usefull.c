/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Usefull functions of Navy
*/

#include "head.h"

void get_my_pid(void)
{
    misc.my_pid = getpid();

    my_putstr("my_pid: ");
    my_putnbr(misc.my_pid);
    my_putchar('\n');
}

int get_positions(char *file)
{
    struct stat buffer;
    int fd;
    int len = 0;

    misc.buff = NULL;
    stat(file, &buffer);
    fd = open(file, O_RDONLY);
    if (fd == -1) {
        write(2, "No such file or directory\n", 27);
        return (84);
    }
    len = buffer.st_size;
    misc.buff = malloc(sizeof(char) * (len + 1));
    read(fd, misc.buff, len);
    if (misc.buff[0] == '\0') {
        write(2, "Empty file\n", 12);
        return (84);
    }
    close(fd);
    return (0);
}

void malloc_board_one(void)
{
    misc.my_board = (int **)malloc(8 * sizeof(int *));
    for (int i = 0; i < 8; i++)
        misc.my_board[i] = (int *)malloc(8 * sizeof(int));
}

void malloc_board_two(void)
{
    misc.other_board = (int **)malloc(8 * sizeof(int *));
    for (int i = 0; i < 8; i++)
        misc.other_board[i] = (int *)malloc(8 * sizeof(int));
}