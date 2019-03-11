/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Player one Navy
*/

#include "head.h"

void sig_handler_one(int useless_int, siginfo_t *sig_use, void *useless_data)
{
    (void)useless_int;
    (void)useless_data;
    misc.sig_tool = sig_use->si_pid;
}

int routine_one(void)
{
    while (1) {
        my_putstr("attack: ");
        misc.input = get_next_line(0);
        if (check_target() == 1)
            break;
    }
    shoot();
    query();
    if (my_win_checker() == 2)
        return (1);
    if (other_win_checker() == 2)
        return (1);
    receive();
    target();
    if (my_win_checker() == 2)
        return (1);
    if (other_win_checker() == 2)
        return (1);
    return (0);
}

int gameplay_one(void)
{
    misc.other_pid = misc.sig_tool;
    misc.sig_tool = 0;
    kill(misc.other_pid, 10);
    my_putstr("\nenemy connected\n");
    while (1) {
        print_clear_board(misc.my_board);
        print_hide_board(misc.other_board);
        my_putchar('\n');
        if (routine_one() == 1)
            break;
    }
    return (0);
}

int player_one(char *file)
{
    struct sigaction sig_use;

    misc.my_board = NULL;
    misc.other_board = NULL;
    sig_use.sa_flags = SA_SIGINFO;
    sig_use.sa_sigaction = sig_handler_one;
    malloc_board_one();
    malloc_board_two();
    if (get_positions(file) == 84)
        return (84);
    if (parse_value() == 84)
        return (84);
    get_my_pid();
    my_putstr("waiting for enemy connection...\n");
    sigaction(10, &sig_use, 0);
    pause();
    gameplay_one();
    return (0);
}
