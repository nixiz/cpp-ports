#include "ClassII.h"
#include "ClassI.h"

ClassII::ClassII()
{
	REGISTER_PORT(portIn);
	REGISTER_PORT(portInOut);
}

ClassII::~ClassII()
{
}

void ClassII::SetDouble(double val)
{
	mVal = val;
	mVal += PORT(portInOut)->GetInt();
}

double ClassII::GetDouble() const
{
	return mVal;
}
