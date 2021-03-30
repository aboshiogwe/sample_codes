#ifndef _CH10SHOPPER_H
#define _CH10SHOPPER_H
#include "Cart.h"

class Shopper
{
private:
	float wallet;

public:
	Shopper() { wallet = 100.00; }
	Item ReadItemFromList();

	Cart SqueakyWheels;   // our shopper has a cart called SqueekyWheels
	float GetMoneyFromWallet(float);
	float MoneyLetInWallet() { return wallet; }
};

#endif