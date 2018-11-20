#include "../../includes/vm.h"

#define LEN 2048

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

void display(t_vm *vm, int step)
{
    int *ram;
   // if (step == 3)
    if (step == 1)
        create_visualizer(&vm->display);
    if (step == 2)
    {
        ram = ft_simulate_ram();
        getchar();
        ft_print_ram(ram);
        //printw("hello");
        //refresh();
    }
     //display_winner(&vm->display);
    //update_ram();
}
