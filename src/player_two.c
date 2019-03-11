/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Player two Navy
*/

#include "head.h"

void sig_handler_two(int sig)
{
    if (sig == SIGUSR1)
        my_putstr("successfully connected\n");
}

int routine_two(void)
{
    receive();
    target();
    if (my_win_checker() == 2)
        return (1);
    if (other_win_checker() == 2)
        return (1);
    my_putchar('\n');
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
    return (0);
}

int gameplay_two(void)
{
    int x = 0;

    misc.sig_tool = 0;
    while (x != 1) {
        print_clear_board(misc.my_board);
        print_hide_board(misc.other_board);
        if (routine_two() == 1)
            break;
    }
    return (0);
}

int player_two(char *PID, char *file)
{
    misc.my_board = NULL;
    misc.other_board = NULL;
    malloc_board_one();
    malloc_board_two();
    if (get_positions(file) == 84)
        return (84);
    if (parse_value() == 84)
        return (84);
    get_my_pid();
    misc.other_pid = my_getnbr(PID);
    kill(misc.other_pid, SIGUSR1);
    signal(10, sig_handler_two);
    pause();
    gameplay_two();
    return (0);
}
