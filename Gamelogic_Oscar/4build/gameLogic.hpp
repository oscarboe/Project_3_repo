#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
class gameLogic
{
private:
    
    
    int gameResult_=0;
    int nearNum_=100-26;
    int loseNum_=37;
    
    //using the highest precision possible because rand is only guarenteed to be at least 32767
    int winRatios_[13]={0,5041,9662,13863,17644,21004,23945,26466,28566,30246,315067,32347,32767};
    
    int lastSpin_=-1;
   
public:
    gameLogic(/* args */)
    {}
    //int payout_ [13]={0,1,1,2,2,3,3,4,4,5,5,6,28};
    int symbolNumber_;
    int runGame();
    int lostGame(int);
    int wonGame();
    int nearGame(int);
    int convertToSendable(int,int);
   
    ~gameLogic()
    {}
};