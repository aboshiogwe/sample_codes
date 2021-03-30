#include "Cart.h"
#include "Clerk.h"

Item Clerk::FigureTotal(Cart *pCart, float *COST, float *PurchaseNo)
{
	int i, CheckOutTotal;
	Item TheItem;
	CheckOutTotal = pCart->HowManyInCart();

	for (i = 0; i < CheckOutTotal; ++i)
	{
		TheItem = pCart->RetrieveNextItem();
		total = TheItem.price + total;
		noItem = TheItem.quantity + noItem;
	}
	*COST = total + ((5/100) * total);
	*PurchaseNo = noItem;
	return TheItem;
}