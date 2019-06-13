#include "ClassIII.h"
#include "ClassI.h"


ClassIII::ClassIII()
{
}


ClassIII::~ClassIII()
{
}

double ClassIII::TestPorts(int nVal, double dVal)
{
	PORT(portI)->SetInt(nVal);
	PORT(portII)->SetDouble(dVal);
	return static_cast<ClassI*>(PORT(portI))->GetDoubleFromPort();
}