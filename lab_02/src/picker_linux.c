#if defined __linux__ || defined __APPLE__
#include "keys.h"
#include "picker.h"
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

void clear_console()
{
    system("clear");
}

void set_cursor_to_start()
{
    printf("\033[;H");
}

static struct termios old, current;

void init_termios()
{
    tcgetattr(0, &old);
    current = old;
    current.c_lflag &= ~ICANON;
    current.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &current);
}

void reset_termios(void)
{
    tcsetattr(0, TCSANOW, &old);
}


key_e read_key()
{
    init_termios();
    int c = fgetc(stdin);
    if (c == 27)
    {
        c = fgetc(stdin);
        if (c == 91)
        {
            c = fgetc(stdin);
            reset_termios();
            if (c == 65)
                return UP_KEY;
            if (c == 66)
                return DOWN_KEY;
        }
    }
    else if (c == 10)
    {
        reset_termios();
        return ENTER_KEY;
    }
    reset_termios();
    return DEFAULT_KEY;
}

#endif

