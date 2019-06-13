#include <iostream>
#include <port.hpp>
#include "ClassI.h"
#include "ClassII.h"
#include "ClassIII.h"

class DerivedClassI : protected ClassI
{
public:
	DerivedClassI() : ClassI()
	{

	}

	auto TestDerivedClassI()
	{
		return PORT(portInOut)->GetDouble();
	}
};

int main()
{
	ClassI i;
	ClassII ii;
	ClassIII iii;
	auto result = iii.TestPorts(1, 2.14);
	std::cout << "result: " << result << "\n";
	DerivedClassI d;
	std::cout << "result: " << d.TestDerivedClassI() << "\n";
}