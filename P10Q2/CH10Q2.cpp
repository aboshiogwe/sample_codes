//Interaction betwwen Shopper and Check-out Clerk   The Shopper has a Cart

#include "Cart.h"
#include "Clerk.h"
#include "Shopper.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

int ReadShoppingList(Item[], int *);

int main()
{
	Item Goods[50], C_Goods[50];
	Shopper Ed;
	Clerk Gladys;
	int total;

	float HowMuchEdOwes, TotalPurchased, PayOut;

	ReadShoppingList(Goods, &total);

	Ed.SqueakyWheels.AddItemToCart(Goods, &total);
	
	C_Goods[total] = Gladys.FigureTotal(&Ed.SqueakyWheels, &HowMuchEdOwes, &TotalPurchased);

	std::cout << "\n Items scanned and their respective cost are ";
	for (int i = 0; i < total;i++)
	{
		std::cout << std::setw(8) << C_Goods[i].name << std::setw(8) << C_Goods[i].price << std::endl;
	}
	std::cout << "\n Ed owes Gladys " << HowMuchEdOwes;
	std::cout << "\nThis includes 5 percent sales tax of the total amount ";
	std::cout << "\n Ed purchased " << TotalPurchased << " items";
	
	PayOut = Ed.GetMoneyFromWallet(HowMuchEdOwes);

	std::cout << "\n Ed pays Gladys " << PayOut;
	std::cout << "\n Money let in Ed's wallet is " << Ed.MoneyLetInWallet() << " dollars";

	std::cout << "\n\n Shopping is hard work! \n";
	std::cin.get();
}

int ReadShoppingList(Item Goods[], int *total)
{
	int NoLines = 0, Pr;
	std::string lines, Name;
	float Qu;
	char junk;

	std::ifstream input;

	input.open("StuffToBuy.dat", std::ios::in | std::ios::_Nocreate);
	if (!input) return 1;
	while (getline(input, lines))
		++NoLines;

	*total = NoLines;
	for (int i = 0;i < *total;++i)
	{
		input.getline(Name, 20);
		input >> Pr >> Qu;
		input.get(junk);

		strcpy_s(Goods[i].name, Name);
		Goods[i].price = Pr;
		Goods[i].quantity = Qu;
	}
	input.close();
	return 0;
}
