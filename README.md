# Ports for C++

Ports for C++ is a header-only library for creating relations (associations) between classes without sharing their instances.
<!-- Supports C++98 standards.
It can be used with C++98 compilers. --> 

## Port Structure and Usage
<!-- Port sınıfı ile kendini register eden bir nesne(instance), hedef port sınıfları üzerinden
erişilebilir hale gelmektedir. Bu sayede Sınıflar birbirlerine dolaylı olarak erişme imkanı
bulurlar; bir sınıfı diğer sınıfa iletmeden bu işlem mümkün hale gelir. -->

**For detailed examples please look [Demos](https://github.com/nixiz/cpp-ports/tree/master/demo).**

Port structure is simple template class that holds the pointers of given types. An object that registers itself with the Port class, it will becomes accessible over the target classes. This allows classes to access each others instance indirectly without sharing the instance.

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

<!-- 'ClassA' sınıfının 'ClassB' sınıfı ile iki taraflı bir bağ kurması yani iki sınıfın da birbirini çağırabilir hale gelmesi için Port sınıfına kendini ve erişmek istediği tipi belirtir. -->

Class declares a Port class with itself(to make itself accessible to target class) and target class so Port establishes a two-way relation with given classes.

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

<!-- Bu bağın kurulabilmesi için 'ClassB' sınıfı da kendisini register edecek şekilde Port sınıfını tanımlar. -->
To create this relation successfully Class B also needs to declare same port with opposite order with template types.

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
<!-- Port sınıfı bu iki tipte verilen sınıfların nesneleri için iki tane pair tanımlar ve bu pairler statik olarak tanımlandıkları için sınıfların yaratıldıklarında kendilerini register etmeleri, bağın kurulması için yeterli olacaktır. -->

### Register Port with given `InType`

<!-- Port sınıfına In type belirten bütün sınıflar, ilgili tipin nesnesini kayıt etmelidirler -->
<!-- All classes that declared a In type to Port should register the instances of declared In type. -->
All classes that specify In type in the port class must register the object of that type.

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

<!-- Since Port structure holds the instances, classes are no more need to get associated instances. -->
<!-- Register işlemlerinden sonra iki sınıf da birbirini istediği zaman çağırabilir hale gelmiştir. -->
After these operations, the relations defined with the Port class can be used as followed

```cpp
// From ClassA instance to ClassB function call
ClassA::foo()
{
  portB::OutPtr()->bar();
  // or use port with macro
  PORT(portB)->bar();
}
```

## Limitations  

Will be updated.
<!-- 
  Port Sınıfları pair olarak sınıfları taşıdıklarından dolayı,
  her tip için bir instance olmak zorundadır. Aksi takdirde aynı
  tipte verilen instance'lar o port'un tuttuğu instance'ın üzerine 
  yazacaktır.
 -->

## License

This library is licensed under the MIT License - see the LICENSE file for details.
