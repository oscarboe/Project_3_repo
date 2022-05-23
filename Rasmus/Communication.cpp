#include "Communication.h"
#include "gameLogic.h"



Communication::Communication()
{

	wheelOneOldPos_ = 1;
	wheelTwoOldPos_ = 1;
	wheelThreeOldPos_ = 1;
}

void Communication::sendData()
{
	sendWheelOne();
	sendWheelTwo();
	sendWheelThree();
	dataSent();
}

void Communication::sendWheelOne()
{
	if (wheelOneOldPos_ != getWheelOne())
	{
		//send 2x wheel number and placement
		wheelOneOldPos_ = getWheelOne();
	}
}

void Communication::sendWheelTwo()
{
	if (wheelOneOldPos_ != getWheelTwo())
	{
		//send 2x wheel number and placement
		wheelTwoOldPos_ = getWheelTwo();
	}
}

void Communication::sendWheelThree()
{
	if (wheelThreeOldPos_ != getWheelThree())
	{
		//send 2x wheel number and placement
		wheelThreeOldPos_ = getWheelThree();
	}
}

void Communication::dataSent()
{
	// send 2x Bytes 11111111

}



void Communication::sendPayout()
{
	
	getPayout();
	// send getPayout();

	resetPayout();
}

