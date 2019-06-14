# Ports for C++
Ports is header-only library for creating and using associations between classes and interfaces. It can be used even with C++98 compilers.

**Looking for demo? Go to [Demo Page](https://github.com/nixiz/cpp-ports/tree/master/demo/interface).**

## Port Structure and Usage

The port structure is simple template class that holds the pointers of given types.
```cpp
template <class In, class Out>
class Port
{
public:
  typedef In  InType;
  typedef Out OutType;
  ...
private:
  static InPtrType  in_ptr;
  static OutPtrType out_ptr;
};
```

### Declare Ports Definition in Class
```cpp
// ClassA.h
class ClassB; // associated classes can be forward declared.
class ClassA
{
  typedef Port<ClassA, ClassB> portB;
public:
  ClassA() = default;
  ...
};
```

```cpp
// ClassB.h
class ClassA;
class ClassB
{
  typedef Port<ClassB, ClassA> portA;
public:
  ClassB() = default;
  ...
};
```

### Register Port with given `InType`

```cpp
// ClassA.cpp
ClassA::ClassA() 
{
  PortBinder<portB::InType, portB::OutType>::Register(this);
  // or register with macro
  REGISTER_PORT(portB);
}
```
```cpp
// ClassB.cpp
ClassB::ClassB() 
{
  REGISTER_PORT(portA);
}
```
### Port Usage With Given Association

Since Port structure holds the instances, classes are no more need to get associated instances. 

```cpp
// From ClassA instance to ClassB function call
ClassA::foo() 
{
  portB::OutPtr()->bar();
  // or use port with macro
  PORT(portB)->bar();
}
```


