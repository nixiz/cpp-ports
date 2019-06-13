#pragma once
#include "interfaces.h"
#include "port.hpp"

class ClassII :
	public InterfaceII
{
	// in & out port declerations must be declared by each class with opposite interface order.
	DECLARE_PORT_IN_OUT(InterfaceII, InterfaceI) portInOut;
	DECLARE_PORT_IN(InterfaceII) portIn;
public:
	ClassII();
	~ClassII();

	void SetDouble(double val) override;
	double GetDouble() const override;
protected:
	double mVal = .0;
};

