#pragma once
#include "interfaces.h"
#include <port.hpp>

class ClassIII
{
	DECLARE_PORT_OUT(InterfaceI) portI;
	DECLARE_PORT_OUT(InterfaceII) portII;

public:
	ClassIII();
	~ClassIII();

	double TestPorts(int nVal, double dVal);
};

