#pragma once
#include <port.hpp>

class ClassI;
class ClassII
{
	DECLARE_PORT_IN_OUT(ClassII, ClassI) portInOut;
	DECLARE_PORT_IN(ClassII) portIn;
public:
	ClassII();
	~ClassII();

	void SetDouble(double val);
	double GetDouble() const;
protected:
	double mVal = .0;
};

