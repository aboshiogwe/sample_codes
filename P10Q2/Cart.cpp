#include "Cart.h"

Item Cart::RetrieveNextItem()
{
	Item next;
	next = stuff[WhichItem];
	++WhichItem;
	return next;
}

void Cart::AddItemToCart(Item newthing[], int *T)
{
	for (int i = 0;i < *T;++i)
	{
		stuff[i] = newthing[i];
	}
	HowMany = *T;
}
