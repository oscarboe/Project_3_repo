#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
class gameLogic
{
private:
    int gameresult_=0;
public:
    gameLogic(/* args */);
    int runGame();
    ~gameLogic();
};

gameLogic::gameLogic(/* args */)
{
}

gameLogic::~gameLogic()
{
}
