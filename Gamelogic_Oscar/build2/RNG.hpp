#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
class gameLogic
{
private:
    int gameresult_=0;
    int lose_num=33;
    int near_num=66;
    int winRatios_[13]={0,8,16,24,32,40,48,56,64,72,80,88,96};
    int symbolNumber_;
    int lastSpin_=-1;
   
public:
    gameLogic(/* args */)
    {}
    int runGame();
    void lostGame();
    void wonGame();
    void nearGame();
    ~gameLogic()
    {}
};