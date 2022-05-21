#include "RNG.hpp"
#include <unistd.h>
gameLogic a;
int main(void)
{
    for(;;)
    {
    a.runGame();
    sleep(1);
    }
}