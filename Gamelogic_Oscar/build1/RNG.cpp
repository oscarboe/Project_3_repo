#include "RNG.hpp"

int gameLogic::runGame ()
{
  srand (time(NULL));
  gameresult_ = (rand()%3+1);

if (gameresult_==1)
{
    printf("game is lost\n");
}
else if (gameresult_==2)
{
    printf("game is lost but it was a near miss\n");
}
else if (gameresult_==3)
{
    printf("Congratulations! you won \n");
}
else
{
    printf("error");
    return 0;
}
  return gameresult_;
}