#include "gameLogic.hpp"
#include <unistd.h>
gameLogic GL;
int main(void)
{
    srand (time(NULL));
    int wonSymbol
    for(;;)
    {
    
    switch (GL.runGame())
    {
    case 0:
        comunication.send(GL.lostGame(1));
        comunication.send(GL.lostGame(2));
        comunication.send(GL.lostGame(3));
        //data.end
        break;
    
    case 1:
        
        comunication.send(GL.nearGame(1));
        comunication.send(GL.nearGame(2));
        comunication.send(GL.nearGame(3));
        break;

    case 2:
        communication.send(GL.wonGame());
        communication.send(GL.convertToSendable(GL.symbolNumber_,2));
        communication.send(GL.convertToSendable(GL.symbolNumber_,3));

        communication.sendPayout(GL.symbolNumber_);
        
        break;
    default:
        break;
    }
    sleep(1);
    }
    
}