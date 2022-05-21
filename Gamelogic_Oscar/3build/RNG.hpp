#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
class gameLogic
{
private:
    void lostGame();
    void wonGame();
    void nearGame();
    int convertToSendable(int );
    int gameResult_=0;
    int nearNum_=100-26;
    int loseNum_=37;
    
    //using the highest precision possible because rand is only guarenteed to be at least 32767
    int winRatios_[13]={0,5041,9662,13863,17644,21004,23945,26466,28566,30246,315067,32347,32767};
    int symbolNumber_;
    int lastSpin_=-1;
    int wheel_=1;
   
public:
    gameLogic(/* args */)
    {}
    int runGame();
   
    ~gameLogic()
    {}
};