#include "gameLogic.hpp"
#include "communication.h"
//#include "credit.hpp" skal laves af Tonny og Heja
#include <unistd.h>


gameLogic GL;
//credit Cre; MANGLER
communication Com;



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
                    Com.dataSent();
                    break;

                case 1:
                    Com.send(GL.nearGame(1));
                    Com.send(GL.nearGame(2));
                    Com.send(GL.nearGame(3));
                    Com.dataSent();
                    break;

                case 2:
                    Com.send(GL.wonGame());
                    Com.send(GL.convertToSendable(GL.symbolNumber_, 2));
                    Com.send(GL.convertToSendable(GL.symbolNumber_, 3));
                    Com.dataSent();
                    Com.sendPayout(GL.symbolNumber_);
                    break;
                default:
                    break;
                }
                C.creditDecrement();
                sleep(1);
            }
        }
    }


