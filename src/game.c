/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Game one Navy
*/

#include "head.h"

int shoot(void)
{
    int send = 0;

    misc.input_alpha = misc.input[0] - 65;
    misc.input_digit = misc.input[1] - '0';
    while (send != misc.input_alpha) {
        kill(misc.other_pid, 10);
        usleep(1);
        send++;
    }
    send = 0;
    kill(misc.other_pid, 12);
    while (send != misc.input_digit) {
        kill(misc.other_pid, 10);
        usleep(1);
        send++;
    }
    kill(misc.other_pid, 12);
    return (0);
}

void sig_query(int signum)
{
    if (signum == 10) {
        misc.other_board[misc.input_digit - 1][misc.input_alpha] = 10;
        my_putstr(misc.input);
        my_putstr(": hit\n");
    }
    else if (signum == 12) {
        if (misc.other_board[misc.input_digit - 1][misc.input_alpha] == 0)
            misc.other_board[misc.input_digit - 1][misc.input_alpha] = 20;
        my_putstr(misc.input);
        my_putstr(": missed\n");
    }
}

int query(void)
{
    signal(10, sig_query);
    signal(12, sig_query);
    pause();
    return (0);
}

void sig_receiver(int signum)
{
    if (signum == 10) {
        misc.sig_tool += 1;
    }
    else if (signum == 12) {
        if (misc.delimiter == 0) {
            misc.input_alpha = misc.sig_tool;
            misc.sig_tool = 0;
            misc.delimiter = 1;
        }
        else if (misc.delimiter == 1) {
            misc.input_digit = misc.sig_tool;
            misc.sig_tool = 0;
            misc.delimiter = 2;
        }
    }
}

int receive(void)
{
    misc.delimiter = 0;
    misc.sig_tool = 0;
    my_putstr("\nwaiting for enemy's attack...\n");
    while (1) {
        signal(10, sig_receiver);
        signal(12, sig_receiver);
        if (misc.delimiter == 2)
            break;
    }
    return (0);
}