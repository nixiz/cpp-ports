/*
 Copyright (c) Oguzhan KATLI
 Licensed under the MIT license.
*/
#ifndef _PORT_HPP
#define _PORT_HPP

#define DECLARE_PORT_IN(in) typedef Port<in, EmptyType>
#define DECLARE_PORT_OUT(out) typedef Port<EmptyType, out>
#define DECLARE_PORT_IN_OUT(in, out) typedef Port<in, out>
#define PORT(prt) prt::OutPtr()

/** works in gcc compilers only!
* #define _GET_OVERRIDE(_1, _2, Name, ...) Name
* #define DECLARE_PORT(...) _GET_OVERRIDE(__VA_ARGS__, DECLARE_PORT_IN_OUT, DECLARE_PORT_IN)(__VA_ARGS__)
*/
#define REGISTER_PORT(Port) PortBinder<Port::InType, Port::OutType>::Register(this)
#define CREATE_ELEMENT_WITH_CODE(name) void Test##name()

class EmptyType {};

template <class In, class Out>
class Port
{
public:
	typedef In  InType;
	typedef Out OutType;

	typedef InType*  InPtrType;
	typedef OutType* OutPtrType;

	template <class I, class O>
	friend class PortBinder;

	static InPtrType InPtr() {
		return in_ptr;
	}

	static OutPtrType OutPtr() {
		return out_ptr;
	}

private:
	static InPtrType  in_ptr;
	static OutPtrType out_ptr;
};

template <class In, class Out>
typename Port<In, Out>::InPtrType  Port<In, Out>::in_ptr = nullptr;

template <class In, class Out>
typename Port<In, Out>::OutPtrType Port<In, Out>::out_ptr = nullptr;

// DECLARE_PORT_IN_OUT(portIn, portOut) makrosu ile tanımlanmış interfaceler için özelleştirilmiştir
// REGISTER_PORT dendiğinde burası çalışır
template <class In, class Out>
class PortBinder
{
public:
	template <class Servant>
	static void Register(Servant * inptr)
	{
		Port<In, Out>::in_ptr = inptr;
		Port<Out, In>::out_ptr = inptr;
	}
};

// DECLARE_PORT_IN(port) makrosu ile tanımlanmış interfaceler için özelleştirilmiştir
// REGISTER_PORT dendiğinde burası çalışır
template <class In>
class PortBinder<In, EmptyType>
{
public:
	template <class Servant>
	static void Register(Servant * inptr)
	{
		Port<In, EmptyType>::in_ptr = inptr;
		Port<EmptyType, In>::out_ptr = inptr;
	}
};

// DECLARE_PORT_OUT(port) makrosu ile tanımlanmış interfaceler için özelleştirilmiştir
// REGISTER_PORT dendiğinde burası çalışır
template <class Out>
class PortBinder<EmptyType, Out>
{
public:
	// Out register'lar için bir şey yapmaya gerek yok zaten ilgili
	// port pair'i in tipindeki sınıf register ettiğinde oluşacaktır.
	static void Register(void *) { }
};

#endif
