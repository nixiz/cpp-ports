#include <iostream>
#include "ClassI.h"
#include "ClassII.h"
#include "ClassIII.h"

int main()
{
	ClassI i;
	ClassII ii;
	ClassIII iii;
	auto result = iii.TestPorts(1, 2.14);

	return 0;
}