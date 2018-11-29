#include "../../includes/vm.h"

void    delete_display(t_win *display)
{
    delwin(display->win_left);
    delwin(display->win_right);
    delwin(display->win_down);
    delwin(display->win);
    endwin();
}

void    display_winner(t_win *display)
{
    delete_display(display);
}