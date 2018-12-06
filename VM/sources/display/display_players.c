#include "../../includes/vm.h"

void    color_jauge(float res, int total, int lives)
{
    attron(COLOR_PAIR(9));
    while (res > 0)
    {
        addch(' ');
        res--;
    }
    attron(COLOR_PAIR(3));
    while (total > -7)
    {
        addch(' ');
        total--;
    }
    attron(COLOR_PAIR(5));
    printw("%d", lives);
    refresh();
}

void    create_jauge(float total_lives, float lives, int int_lives)
{
    float   res;
    int     total;

    clrtoeol();
    refresh();
    if (lives == 0)
        color_jauge(0, 100, int_lives);
    else
    {
        res = lives / total_lives * 100;
        total = 100 - res;
        color_jauge(res, total, int_lives);
    }
}

void    print_players_share(t_vm *vm)
{
    int i;
    int top;
    int left;

    i = 0;
    top = LINES / 4 * 3 + 4;
    left = vm->display.name_len + 7;
    while (i < vm->num_players)
    {
        move(top, left);
        create_jauge((float)vm->lives_current, (float)vm->players[i].nb_live, vm->players[i].nb_live);
        i++;
        top = top + 2;
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
    while (i < vm->num_players)
    {
        ft_choose_color(i + 1);
        move(top, left);
        printw("%s", vm->players[i].header.prog_name);
        if (ft_strlen(vm->players[i].header.prog_name) > vm->display.name_len)
            vm->display.name_len = ft_strlen(vm->players[i].header.prog_name);
        top = top + 2;
        i++;
    }
    refresh();
}