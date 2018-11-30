#include "../../includes/vm.h"

/*void    color_jauge(float green)
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
}*/

void    create_jauge(float total_lives, float lives)
{
    float   res;

    clrtoeol();
    refresh();
    if (lives == 0)
        return ;
    res = lives / total_lives * 100;
    attron(COLOR_PAIR(9));
    while (res > 0)
    {
        addch(' ');
        res--;
    }
    refresh();
}

void    print_players_share(t_vm *vm)
{
    int i;
    int top;
    int left;

    i = 0;
    top = LINES / 4 * 3 + 4;
    left = vm->display.name_len + 7;
    while (i < vm->nbplayers)
    {
        move(top, left);
       // printw("%d", vm->players[i].nb_live);
        create_jauge((float)vm->lives, (float)vm->players[i].nb_live);
        i++;
        top = top + 2;
       // getch();
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
    vm->display.name_len = 0;
  //  attron(COLOR_PAIR(5));
 //   getch();
    while (i < vm->nbplayers)
    {
        ft_choose_color(i + 1);
        move(top, left);
        printw("%s", vm->players[i].header->prog_name);
        if (ft_strlen(vm->players[i].header->prog_name) > vm->display.name_len)
            vm->display.name_len = ft_strlen(vm->players[i].header->prog_name);
        top = top + 2;
        i++;
      //  getch();
    }
    refresh();
}