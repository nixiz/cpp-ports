#pragma once

struct InterfaceI
{
	virtual void SetInt(int val) = 0;
	virtual int GetInt() const = 0;
};

struct InterfaceII
{
	virtual void SetDouble(double val) = 0;
	virtual double GetDouble() const = 0;
};
