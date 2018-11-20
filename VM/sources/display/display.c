#include "../../includes/vm.h"

#define LEN 4096

void    ft_choose_color(int player)
{
    if (player == 0)
        attron(COLOR_PAIR(3));
    else if (player == 1)
        attron(COLOR_PAIR(1));
    else if (player == 2)
        attron(COLOR_PAIR(4));
    else if (player == 3)
        attron(COLOR_PAIR(7));
    else if (player == 4)
        attron(COLOR_PAIR(8));

}

void    print_ram(t_case *ram)
{
    int i;
    int col;
    int stop;

    i = 0;
    col = 2;
    stop = 3;
    move(col, 4);
    while (i < LEN)
    {
        if (stop > (COLS / 4) * 3 - 3)
        {
            move(col++, 4);
            stop = 3;
        }
        ft_choose_color(ram[i].pid);
        printw("%.2x ", ram[i]);
        stop = stop + 3;
        i++;
    }
    refresh();
}

void display(t_vm *vm, int step)
{
    //int *ram;
   // if (step == 3)
   int COL = COLS;
   int  LI = LINES;
   printf("COLS = %d - cols = %d\n", COL, vm->display.cols);
   printf("LINES = %d - lines = %d\n", LI, vm->display.lines);
   getchar();
    if (step == 1 || COLS != vm->display.cols || LINES != vm->display.lines)
    {
        create_visualizer(&vm->display);
        vm->display.lines = LINES;
        vm->display.cols = COLS;
    }
   // if (step == 2)
   // {
        //ram = ft_simulate_ram();
       // getchar();
    print_ram(vm->ram);
        //printw("hello");
        //refresh();
  //  }
     //display_winner(&vm->display);
    //update_ram();
}
