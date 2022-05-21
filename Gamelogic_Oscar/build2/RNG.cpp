#include "RNG.hpp"

int gameLogic::runGame ()
{
  
  gameresult_ = (rand()%99+1);

if (gameresult_<=lose_num)
{
    printf("game is lost%d\n",gameresult_);
    lostGame();
}
else if (gameresult_<=near_num)
{
    printf("game is lost but it was a near miss %d\n",gameresult_);
    nearGame();
}
else if (near_num<gameresult_)
{
    printf("Congratulations! you won %d\n", gameresult_);
    wonGame();
}
else
{
    printf("error");
    return 0;
}
  return gameresult_;
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
        lastSpin_=i;
        break;
      }
    }
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
      //print out the result on each wheel
      break;
    }
  }

}