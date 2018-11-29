#include "../../includes/vm.h"

#define LEN 1900

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
        if (stop > (COLS / 5) * 4 - 3)
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

void    move_clear_print(int x, int y, int print)
{
    move(x, y);
    clrtoeol();
    move(x, y);
    printw("%d", print);
}

void    print_infos(t_vm *vm)
{
    int margin_top;
    int margin_left;

    margin_top = LINES / 5;
    margin_left = (COLS / 5) * 4 + 32;
    attron(COLOR_PAIR(5));
    move_clear_print(margin_top, margin_left, vm->nbplayers);
    move_clear_print(margin_top + 4, margin_left, vm->stack.nbprocess);
    move_clear_print(margin_top + 8, margin_left, vm->lives);
    move_clear_print(margin_top + 12, margin_left, vm->cycles_to_die);
    move_clear_print(margin_top + 16, margin_left, vm->cycles_left);
    getch();
    refresh();
}

void    display(t_vm *vm, int step)
{
  // int COL = COLS;
   //int  LI = LINES;
 //  printf("COLS = %d - cols = %d\n", COL, vm->display.cols);
   //printf("LINES = %d - lines = %d\n", LI, vm->display.lines);
    if (step == 1 /*|| COLS != vm->display.cols || LINES != vm->display.lines*/)
    {
        create_visualizer(vm, &vm->display);
        //print_ram(vm->ram);
      //  vm->display.lines = LINES;
        //vm->display.cols = COLS;
    }
    print_ram(vm->ram);
    print_infos(vm);
    print_players_share(vm);
}
