#pragma once
#include <port.hpp>

class ClassI;
class ClassII;
class ClassIII
{
	DECLARE_PORT_OUT(ClassI) portI;
	DECLARE_PORT_OUT(ClassII) portII;
public:
	ClassIII();
	~ClassIII();
	double TestPorts(int nVal, double dVal);
};
