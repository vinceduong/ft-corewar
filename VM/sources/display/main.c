#include <ncurses.h>
#include <stdlib.h>

#define LEN 2048

void ft_initialiser() {
    initscr();	        /* Demarre le mode ncurses */
    cbreak();	        /* Pour les saisies clavier (desac. mise en buffer) */
    noecho();             /* Desactive l'affichage des caracteres saisis */
    keypad(stdscr, TRUE);	/* Active les touches specifiques */
    refresh();            /* Met a jour l'affichage */
    curs_set(FALSE);      /* Masque le curseur */
}

void ft_init_colors() 
{
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_BLACK);
}

void    ft_init_windows(WINDOW *win, WINDOW *win_left, WINDOW *win_right)
{
    win = newwin(LINES, COLS, 0, 0);
    wbkgd(win, COLOR_PAIR(2)); 
    win_left = subwin(win, LINES - 2, (COLS / 4) * 3, 1, 2);
    wbkgd(win_left, COLOR_PAIR(1));
    win_right = subwin(win, LINES - 2, (COLS /4) * 1 - 6, 1, (COLS / 4) * 3 + 4);
    wbkgd(win_right, COLOR_PAIR(1));
    wrefresh(win);
    wrefresh(win_left);
    wrefresh(win_right);
}

int    *ft_simulate_ram()
{
    int     i;
    int     fill;
    int    *ram;

    i = 0;
    fill = 17;
    if (!(ram = malloc(sizeof(int) * LEN)))
        exit(0);
    while (i < LEN)
    {
        if ((fill > 255) || fill == 10)
            fill = 17;
        if (i > 600 && i < 1200) 
            ram[i] = 0;
        else
            ram[i] = fill;
        fill++;
        i++;
    }
    return (ram);
}

void    ft_print_ram(int *ram)
{
    int i;
    int col;
    int stop;

    i = 0;
    col = 2;
    stop = 3;
    move(col, 4);
    attron(COLOR_PAIR(1));
    while (i < LEN)
    {
        if (stop > (COLS / 4) * 3 - 3)
        {
            move(col++, 4);
            stop = 3;
        }
        if (ram[i] == 0)
        {
            attron(COLOR_PAIR(3));
            printw("00 ");
            attron(COLOR_PAIR(4));
        }
        else
            printw("%x ", ram[i]);
        stop = stop + 3;
        i++;
    }
    refresh();
}

void    ft_print_infos()
{
    int margin_left;
    int margin_top;

    margin_left = (COLS / 4) * 3 + 8;
    margin_top = LINES / 3;
    attron(COLOR_PAIR(6));

    attron(A_DIM);
    move(margin_top, margin_left + 25);
    printw("112");
    move(margin_top + 3, margin_left + 25);
    printw("872");
    move(margin_top + 6, margin_left + 25);
    printw("2");

    attron(A_BOLD);
    move(margin_top, margin_left);
    printw("CYCLE");
    move(margin_top + 3, margin_left);
    printw("CYCLES TO DIE");
    move(margin_top + 6, margin_left);
    printw("NUMBER OF PLAYERS");
    refresh();
}

int     main() 
{
    WINDOW  *win;
    WINDOW  *win_left;
    WINDOW  *win_right;
    int    *ram;

    ft_initialiser();
    ft_init_colors();
    ft_init_windows(win, win_left, win_right);
    ram = ft_simulate_ram();
    ft_print_ram(ram);
    ft_print_infos();
    getchar();
    delwin(win_left);
    delwin(win_right);
    delwin(win);
    endwin();
    return (0);
}
