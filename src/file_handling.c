/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** File handling Navy
*/

#include "head.h"

int check_size(void)
{
    if (misc.buff[0] != '2' || misc.buff[8] != '3' \
    || misc.buff[16] != '4' || misc.buff[24] != '5') {
        write(2, "The ship size are incorrect. Type ./navy -h for help.\n", 55);
        return (84);
    }
    return (0);
}

int check_type(void)
{
    if (is_digit(0) == 1 || is_digit(3) == 1 || is_digit(6) == 1 \
    || is_digit(8) == 1 || is_digit(11) == 1 || is_digit(14) == 1 \
    || is_digit(16) == 1 || is_digit(19) == 1 || is_digit(22) == 1 \
    || is_digit(24) == 1 || is_digit(27) == 1 || is_digit(30) == 1) {
        write(2, "File contain a misplaced character.\n", 37);
        return (84);
    }
    if (is_alpha(2) == 1 || is_alpha(5) == 1 || is_alpha(10) == 1 \
    || is_alpha(13) == 1 || is_alpha(18) == 1 || is_alpha(21) == 1 \
    || is_alpha(26) == 1 || is_alpha(29) == 1) {
        write(2, "File contain a misplaced character.\n", 37);
        return (84);
    }
    if (misc.buff[1] != ':' || misc.buff[4] != ':' || misc.buff[9] != ':' \
    || misc.buff[12] != ':' || misc.buff[17] != ':' || misc.buff[20] != ':' \
    || misc.buff[25] != ':' || misc.buff[28] != ':') {
        write(2, "File contain a misplaced character.\n", 37);
        return (84);
    }
    return (0);
}

int check_char(void)
{
    for (int i = 0; misc.buff[i]; i++) {
        if (misc.buff[i] != '1' && misc.buff[i] != '2' && \
        misc.buff[i] != '3' && misc.buff[i] != '4' && misc.buff[i] != '5' && \
        misc.buff[i] != '6' && misc.buff[i] != '7' && misc.buff[i] != '8' && \
        misc.buff[i] != ':' && misc.buff[i] != 'A' && misc.buff[i] != 'B' && \
        misc.buff[i] != 'C' && misc.buff[i] != 'D' && misc.buff[i] != 'E' && \
        misc.buff[i] != 'F' && misc.buff[i] != 'G' && misc.buff[i] != 'H' && \
        misc.buff[i] != '\n' && misc.buff[i] != '\0') {
            write(2, "Your file contain bad characters. ", 35);
            write(2, "Type ./navy -h for help.\n", 26);
            return (84);
        }
    }
    return (0);
}

int check_length(void)
{
    if (misc.buff[6] - misc.buff[3] != 1 \
    && misc.buff[5] - misc.buff[2] != 1)
        return (84);
    if (misc.buff[14] - misc.buff[11] != 2 \
    && misc.buff[13] - misc.buff[10] != 2)
    return (84);
    if (misc.buff[22] - misc.buff[19] != 3 \
    && misc.buff[21] - misc.buff[18] != 3)
        return (84);
    if (misc.buff[30] - misc.buff[27] != 4 \
    && misc.buff[29] - misc.buff[26] != 4)
        return (84);
    return (0);
}