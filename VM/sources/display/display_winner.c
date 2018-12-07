#include "../../includes/vm.h"

void    winner_screen(WINDOW *win, WINDOW *win_left)
{
    win = newwin(LINES, COLS, 0, 0);
    wbkgd(win, COLOR_PAIR(11)); 
    wrefresh(win);
    win_left = subwin(win, LINES - 2, COLS - 4, 1, 2);
    wbkgd(win_left, COLOR_PAIR(1));
    wrefresh(win_left);
}

void    delete_display(t_win *display)
{
    delwin(display->win_left);
    delwin(display->win_right);
    delwin(display->win_down);
    delwin(display->win);
    endwin();
}

void    print_curtain(char *name)
{
    getch();
    move(LINES / 2 - 2, 0);
    clrtoeol();
    getch();
    move(LINES / 2 - 1, 0);
    clrtoeol();
    getch();
    move(LINES / 2, 0);
    clrtoeol();
    getch();
    move(LINES / 2 + 1, 0);
    clrtoeol();
    getch();
    move(LINES / 2 - 1, COLS / 2 - (ft_strlen(name) + 29) / 2);
    attron(COLOR_PAIR(11) | A_BOLD);
    printw("AND THE WINNER IS %s !!!!", name);
    refresh();
}

void    print_emoji()
{
    int i;
    int y;

    i = 4;
    y = 2;
    while (y < LINES - 1)
    {
        move(y, i);
        while (i < COLS - 2)
        {
            printw("%C  ", L'🏆');
            i = i + 3;
        }
        i = 4;
        y = y + 2;
    }
}

void    display_winner_visu(t_vm *vm, t_win *display)
{
    delete_display(display);
    initialiser();
    init_colors();
    winner_screen(display->win, display->win_left);
    print_emoji();
    print_curtain(vm->players[vm->winner].header.prog_name);
    while (getch() != 'q')
        ;
    delete_display(display);
}