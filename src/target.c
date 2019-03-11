/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Player two Navy
*/

#include "head.h"

int check_target(void)
{
    int size = my_strlen(misc.input);

    if (size > 2 || size < 2) {
        write(1, "wrong position\n", 16);
        return (2);
    }
    if (misc.input[0] != 'A' && misc.input[0] != 'B' && misc.input[0] != 'C' \
    && misc.input[0] != 'D' && misc.input[0] != 'E' && misc.input[0] != 'F' \
    && misc.input[0] != 'G' && misc.input[0] != 'H') {
        write(1, "wrong position\n", 16);
        return (2);
    }
    if (misc.input[1] != '1' && misc.input[1] != '2' && misc.input[1] != '3' \
    && misc.input[1] != '4' && misc.input[1] != '5' && misc.input[1] != '6' \
    && misc.input[1] != '7' && misc.input[1] != '8') {
        write(1, "wrong position\n", 16);
        return (2);
    }
    return (1);
}

int target(void)
{
    int ia = misc.input_alpha;
    int id = misc.input_digit - 1;
    if (misc.my_board[id][ia] != 0 && \
    misc.my_board[id][ia] != 10 && misc.my_board[id][ia] != 20) {
        misc.my_board[id][ia] = 10;
        kill(misc.other_pid, 10);
        my_putchar(ia + 65);
        my_putnbr(misc.input_digit);
        my_putstr(": hit\n");
    }
    else if (misc.my_board[id][ia] == 0 || \
    misc.my_board[id][ia] == 10 || misc.my_board[id][ia] == 20) {
        if (misc.my_board[id][ia] == 0 || misc.my_board[id][ia] == 20)
            misc.my_board[id][ia] = 20;
        kill(misc.other_pid, 12);
        my_putchar(ia + 65);
        my_putnbr(misc.input_digit);
        my_putstr(": missed\n");
    }
    return (0);
}

int my_win_checker(void)
{
    int check = 2;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (misc.my_board[i][j] != 0 && misc.my_board[i][j] != 10 \
            && misc.my_board[i][j] != 20)
                check = 1;
        }
    }
    if (check == 1)
        return (1);
    else if (check == 2) {
        misc.win = 1;
        print_clear_board(misc.my_board);
        print_hide_board(misc.other_board);
        my_putstr("\nEnemy won\n");
        return (2);
    }
    return (0);
}

int other_win_checker(void)
{
    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (misc.other_board[i][j] == 10)
                count++;
        }
    }
    if (count < 14)
        return (1);
    else if (count == 14) {
        misc.win = 0;
        print_clear_board(misc.my_board);
        print_hide_board(misc.other_board);
        my_putstr("\nI won\n");
        return (2);
    }
    return (0);
}
