#include "Shopper.h"
#include <fstream>


float Shopper::GetMoneyFromWallet(float cost)
{
	std::cout << "\n This Shopper has " << wallet << " dollars in his wallet";
	if (cost > wallet)
	{
		std::cout << "\n Not enough money!  Put something back! \n";
		return 0;
	}
	else
	{
		wallet = wallet - cost;
		return cost;
	}
}