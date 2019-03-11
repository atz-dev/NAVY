/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** Header of navy
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <math.h>
#include <dirent.h>
#include <grp.h>
#include <time.h>
#include <pwd.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "structures.h"

usefull_t misc;

/* main.c */
int main(int ac, char **av);
int player_choice(int ac, char **av);

/* error_handling.c */
int is_digit(int i);
int is_alpha(int i);
int check_file(void);
int start_handling(int ac, char **av);
void help_message(void);

/* functions.c */
int my_putnbr(int nb);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_getnbr(char const *str);
void my_putchar(char c);

/* usefull.c */
int get_positions(char *file);
void get_my_pid(void);
void malloc_board_one(void);
void malloc_board_two(void);

/* player_one.c */
int routine_one(void);
int player_one(char *file);
int gameplay_one(void);
void sig_handler_one(int useless_int, siginfo_t *sig_use, void *useless_data);

/* player_two.c */
int routine_two(void);
int player_two(char *PID, char *file);
int gameplay_two(void);
void sig_handler_two(int sig);

/* array_function.c */
char **my_str_to_word_array(char *str);

/* parsing.c */
int fill_board(void);
int fill_pd(int pd1, int pd2, int pa1);
int fill_pa(int pa1, int pa2, int pd1);
int parse_value(void);
void parse_algorithm(int j, int x);

/* board.c */
void print_clear_board(int **board);
void print_hide_board(int **board);

/* getnextline.c */
char *get_next_line(int fd);

/* game_one.c */
int shoot(void);
int query(void);
int receive(void);
void sig_receiver(int signum);
void sig_query(int signum);

/* target.c */
int target(void);
int my_win_checker(void);
int other_win_checker(void);
int check_target(void);

/* file_handling.c */
int check_char(void);
int check_size(void);
int check_type(void);
int check_length(void);