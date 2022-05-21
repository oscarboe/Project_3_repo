#include "RNG.hpp"


int gameLogic::runGame ()
{
  wheel_=1;
  gameResult_ = (rand()%99+1);

if (gameResult_<=loseNum_)
{
    printf("game is lost %d\n",gameResult_);
    lostGame();
}
else if (gameResult_<=nearNum_)
{
    printf("game is lost but it was a near miss %d\n",gameResult_);
    nearGame();
}
else if (nearNum_<gameResult_)
{
    printf("Congratulations! you won %d\n", gameResult_);
    wonGame();
}
else
{
    printf("error");
    return 0;
}
  return gameResult_;
}

void gameLogic::lostGame()
{
  
  for (size_t j = 0; j < 3;j++)
  {
    symbolNumber_=rand()%winRatios_[12];
    for (int i = 1; i < sizeof(winRatios_); i++)
    {
      if(winRatios_[i-1]<=symbolNumber_&&symbolNumber_<winRatios_[i])
      {
        if(lastSpin_==i)
        {
          j--;
          break;
        }
        printf("because of RNG number %d the next/first symbol is symbolnumber %d \n",symbolNumber_,i);
        //print out the result 
        convertToSendable(i);
        
        lastSpin_=i;
        break;
      }
    }

    lastSpin_=-1;
  }
  
  
  
  
}
void gameLogic::nearGame()
{
  symbolNumber_=rand()%winRatios_[12];
  for (int i = 1; i < sizeof(winRatios_); i++)
  {
    if(winRatios_[i-1]<=symbolNumber_&&symbolNumber_<winRatios_[i])
    {
      lastSpin_=i;
      printf("With RNG number %d which results in symbol %d \n",symbolNumber_,i);
      //print out the result twice
      convertToSendable(i);
        
      convertToSendable(i);
        
      break;
    }
  }
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
        convertToSendable(i);
        notDone=0;
        
      }
    }
  }
  lastSpin_=-1;
}
void gameLogic::wonGame()
{
  symbolNumber_=rand()%winRatios_[12];
  for (int i = 1; i < sizeof(winRatios_); i++)
  {
    if(winRatios_[i-1]<=symbolNumber_&&symbolNumber_<winRatios_[i])
    {
      printf("With RNG number %d which results in symbol %d \n",symbolNumber_,i);
      //print out the result on each whee
      convertToSendable(i);
      
      convertToSendable(i);
      
      convertToSendable(i);


      //wheel position is sent

      sendPayout(payout_[symbolNumber_]);
      break;
    }
  }


}

int gameLogic::convertToSendable(int symbolNum)
{
  printf("%d\n",wheel_);
  int sendable=0b00000001<<(8-wheel_);
  printf("%d %d\n",sendable, wheel_);
  sendable=sendable|symbolNum;
  printf("%d\n",sendable);
  if (wheel_==3)
  {
    wheel_=0;
  }
  wheel_++;
  
  return sendable;
}