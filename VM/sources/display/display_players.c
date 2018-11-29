#include "../../includes/vm.h"

void    color_jauge(float green)
{
    int  red;
    int  progress;   

    if (green == 0)
        progress = 0;
    else
        progress = (int)green + 1;
    red = 100 - progress;
    attron(COLOR_PAIR(9));
    while (progress > 0)
    {
        addch(' ');
        progress--;
    }
    attron(COLOR_PAIR(10));
    while (red > 0)
    {
        addch(' ');
        red--;
    }
    refresh();
}

void    create_jauge(int player, t_case *ram)
{
    int i;
    float green;

    i = 0;
    green = 0;
    while (i < MEM_SIZE)
    {
        if (ram[i].pid == player)
            green++;
        i++;
    }
    green = (green / 4096) * 100;
    color_jauge(green);
}

void    print_players_share(t_vm *vm)
{
    int i;
    int top;
    int left;

    i = 0;
    top = LINES / 4 * 3 + 4;
    left = 30;
    while (i < vm->nbplayers)
    {
        move(top, left);
        create_jauge(i + 1, vm->ram);
        i++;
        top = top + 2;
        getch();
    }
}

void    init_players(t_vm *vm)
{
    int i;
    int top;
    int left;

    i = 0;
    top = LINES / 4 * 3 + 4;
    left = 3;
    attron(COLOR_PAIR(5));
    while (i < vm->nbplayers)
    {
        move(top, left);
        printw("%s", vm->players[i].filename);
        top = top + 2;
        i++;
    }
    refresh();
}