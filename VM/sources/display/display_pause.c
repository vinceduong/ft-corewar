#include "../../includes/vm.h"

void    display_pause(t_vm *vm)
{
    if (getch() == 32)
    {
        nodelay(stdscr, 0);
        while (getch() != 32)
        {
            if (getch() == KEY_RIGHT && vm->speed < 249000)
                vm->speed = vm->speed + 50000;
            if (getch() == KEY_LEFT && vm->speed > 49000)
                vm->speed = vm->speed - 50000;
        }
        nodelay(stdscr, 1);
    }

}