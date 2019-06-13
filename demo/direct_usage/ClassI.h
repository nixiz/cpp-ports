#pragma once
#include <port.hpp>

class ClassII;
class ClassI
{
	DECLARE_PORT_IN_OUT(ClassI, ClassII) portInOut;
	using portIn = Port<ClassI, EmptyType>;
protected:
	int mVal = 0;
public:
	ClassI();
	~ClassI();
	double GetDoubleFromPort() const;

	void SetInt(int val);
	int GetInt() const;
};

