#include "ClassI.h"



ClassI::ClassI()
{
	// macro style initialization
	REGISTER_PORT(portInOut);

	// same as REGISTER_PORT(portIn);
	PortBinder<portIn::InType, portIn::OutType>::Register(this); // Servant type automatically reduced from this type
}

ClassI::~ClassI()
{

}

double ClassI::GetDoubleFromPort() const
{
	return PORT(portInOut)->GetDouble();
}

void ClassI::SetInt(int val) 
{
	mVal = val;
}

int ClassI::GetInt() const 
{
	return mVal;
}