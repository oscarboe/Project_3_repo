#include "RNG.hpp"
#include <unistd.h>
gameLogic a;
int main(void)
{
    srand (time(NULL));
    for(;;)
    {
    a.runGame();
    sleep(1);
    }
}