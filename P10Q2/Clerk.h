#ifndef _CH10CLERK_H
#define _CH10CLERK_H

class Clerk
{
private:
	float total, noItem;

public:
	Clerk() { total = 0.0; noItem = 0.0; }
	Item FigureTotal(Cart*, float*, float*);
};

#endif