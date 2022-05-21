#include "gameLogic.hpp"
//#include "credit.hpp" skal laves af Tonny og Heja
#include <unistd.h>


gameLogic GL;
//credit Cre; MANGLER
Communication Com



int main(void)
{
    srand(time(NULL));
    int wonSymbol
       
    
    for (;;)
    {
        if (Cre.checkForCredit)
            Cre.creditIncrement();
        
        if(btnPressed() && Cre.getcredit()) 
        {
                

                switch (GL.runGame())
                {
                case 0:
                    Com.send(GL.lostGame(1));
                    Com.send(GL.lostGame(2));
                    Com.send(GL.lostGame(3));
                    //data.end
                    break;

                case 1:
                    comunication.send(GL.nearGame(1));
                    comunication.send(GL.nearGame(2));
                    comunication.send(GL.nearGame(3));
                    //data.end
                    break;

                case 2:
                    communication.send(GL.wonGame());
                    communication.send(GL.convertToSendable(GL.symbolNumber_, 2));
                    communication.send(GL.convertToSendable(GL.symbolNumber_, 3));
                    //data.end
                    communication.sendPayout(GL.symbolNumber_);
                    break;
                default:
                    break;
                }
                C.creditDecrement();
                sleep(1);
            }
        }
    }


