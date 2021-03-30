#ifndef _CH10CART_H
#define _CH10CART_H

#include <iostream>
#include <string.h>

struct Item
{
	std::string name;
	float price;
	int quantity;
};

class Cart
{
private:
	Item stuff[50];
	int HowMany;
	int WhichItem;

public:
	Cart() { HowMany = 0;  WhichItem = 0; }  // constructor zeros out counter
	//void Setname(char *n) { strcpy_s(stuff.name, n); }
	//void SetOthers(float *pr, int * qu) { strcpy_s(stuff.price, pr); strcpy_s(stuff.quantity, qu); }
	void AddItemToCart(Item newthing[], int*);
	Item RetrieveNextItem();
	int HowManyInCart() { return HowMany; }

};

#endif