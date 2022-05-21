#include "gameLogic.hpp"


int gameLogic::runGame ()
{
  gameResult_ = (rand()%99+1);

if (gameResult_<=loseNum_)
{
    printf("game is lost %d\n",gameResult_);
    return 0;
}
else if (gameResult_<=nearNum_)
{
    printf("game is lost but it was a near miss %d\n",gameResult_);
    return 1;
}
else if (nearNum_<gameResult_)
{
    printf("Congratulations! you won %d\n", gameResult_);
    return 2;
}
else
{
    printf("error");
    return -1;
}
  return gameResult_;
}

int gameLogic::lostGame(int wheelNr)
{
  
  int notDone=1;
  while(notDone)
  {
    symbolNumber_=rand()%winRatios_[12];
    for (int i = 1; i < sizeof(winRatios_); i++)
    {
      if(winRatios_[i-1]<=symbolNumber_&&symbolNumber_<winRatios_[i])
      {
        if(i==lastSpin_)
        {
          break;
        }

        printf("because of RNG number %d the next/first symbol is symbolnumber %d \n",symbolNumber_,i);
        //print out the last result
        convertToSendable(i,wheelNr);
        notDone=0;
        
      }
    }
  }  
}
int gameLogic::nearGame(int wheelNr)
{
  if (wheelNr==2)
  {
    return lastSpin_;
  }
  symbolNumber_=rand()%winRatios_[12];

  int notDone=1;
  while(notDone)
  {
    symbolNumber_=rand()%winRatios_[12];
    for (int i = 1; i < sizeof(winRatios_); i++)
    {
      if(winRatios_[i-1]<=symbolNumber_&&symbolNumber_<winRatios_[i])
      {
        if(i==lastSpin_)
        {
          break;
        }

        printf("the final wheel got RNG number %d which results in symbol %d \n",symbolNumber_,i);
        //print out the last result
        return convertToSendable(i,wheelNr);
        
        notDone=0;
        
      }
    }
  }
  return -1;
}
int gameLogic::wonGame(int wheelNr)
{
  symbolNumber_=rand()%winRatios_[12];
  for (int i = 1; i < sizeof(winRatios_); i++)
  {
    if(winRatios_[i-1]<=symbolNumber_&&symbolNumber_<winRatios_[i])
    {
      printf("With RNG number %d which results in symbol %d \n",symbolNumber_,i);
      //print out the result on each whee
      return convertToSendable(i,wheelNr);
       //wheel position is sent

       
      break;
    }
  }
return -1;

}

int gameLogic::convertToSendable(int symbolNum, int wheel)
{
  printf("%d\n",wheel);
  int sendable=0b00000001<<(8-wheel);
  printf("%d %d\n",sendable, wheel);
  sendable=sendable|symbolNum;
  printf("%d\n",sendable);  
  return sendable;
}