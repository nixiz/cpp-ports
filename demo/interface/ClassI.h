#pragma once
#include "interfaces.h"
#include "port.hpp"

class ClassI :
	public InterfaceI
{
	DECLARE_PORT_IN_OUT(InterfaceI, InterfaceII) portInOut;
	// same as DECLARE_PORT_IN(InterfaceI) portIn; 
	using portIn = Port<InterfaceI, EmptyType>;
public:
	explicit ClassI();
	~ClassI();

	void SetInt(int val) override;
	int GetInt() const override;

	double GetDoubleFromPort() const;
protected:
	int mVal = 0;
};

