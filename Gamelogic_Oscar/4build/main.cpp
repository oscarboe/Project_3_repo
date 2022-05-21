#include "gameLogic.hpp"
//#include "credit.hpp" skal laves af Tonny og Heja
#include <unistd.h>
#include <wiringpi.h>

gameLogic GL;
//credit C; MANGLER

void buttonInterrupt(void);
void sensorInterrupt(void);

int main(void)
{
    srand (time(NULL));
    int wonSymbol
    int btnClicked

    wiringPiSetup();	    // Setup the library
    pinMode(22, INPUT);		// Configure GPIO24 as an input (button)
    pinMode(24, INPUT);		// Configure GPIO22 as an input (sensor)

    // ISR
    wiringPiISR(22, INT_EDGE_FALLING, buttonInterrupt); // button goes low when pressed therefore is falling chosen
    wiringPiISR(24, INT_EDGE_RISING, sensorInterrupt); // sensor goes high when there is detection since rising chosen

    sei();
for (;;)
            {
    if (btnclicked)
    {
                   
        cli();

        //if(C.checkForCredit) function som checker om der er credit (MANGLER)
        {
            // C.creditDecrement();

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
            sleep(1);
        }
        btnclicked = 0;
    }
}


void buttonInterrupt(void)
{
    btnclicked = 1;
}

void sensorInterrupt(void)
{
    //C.creditIncrement();
}