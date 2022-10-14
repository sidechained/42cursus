# Exercise Status

0ex00 - ready for submission
0ex01 - ready for submission
1ex00 - ready for submission
1ex01 - ready for submission
1ex02 - ready for submission  
1ex03 - ready for submission (could add destructors)
1ex04 - ready for submission

# C++ Glossary

## Member Function
- operators and functions that are declared as members of a class

## Constructor
- special method that is automatically called when an object of a class is created
- use the same name as the class, followed by parentheses ()

```
class MyClass {     // The class
  public:           // Access specifier
    MyClass() {     // Constructor
      cout << "Hello World!";
    }
};
```

## Destructor
- destructors are used to destroy the objects that have been created by the constructor within the C++ program
- Destructor names are same as the class name but they are preceded by a tilde

```
class MyClass {     // The class
  public:           // Access specifier
    ~MyClass() {     // Constructor
      cout << "Goodbye Cruel World!";
    }
};
```

## Stack vs Heap Allocation

https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/

### Stack: region in memory, which is automatically managed by the computer (in order to store the local variables, methods and its data used by the function)

Example: 

```
int main()
{
   // All these variables get memory
   // allocated on stack
   int a;
   int b[10];
   int n = 20;
   int c[n];
}
```

### Heap: region in memory which is neither automatically managed by the CPU nor by the programmer (free-floating)

```
int main()
{
   // This memory for 10 integers
   // is allocated on heap.
   int *ptr  = new int[10];
}
```

## new vs malloc(), delete vs free()

https://www.geeksforgeeks.org/new-vs-malloc-and-free-vs-delete-in-c/

Both malloc() and new are used to allocate the memory dynamically in heap. But “new” does call the constructor of a class whereas “malloc()” does not.

free() is a C library function that can also be used in C++, while “delete” is a C++ keyword. free() frees memory but doesn't call Destructor of a class whereas “delete” frees the memory and also calls the Destructor of the class.

## Deletion of array of objects

https://www.geeksforgeeks.org/deletion-of-array-of-objects-in-c/

## Copy Constructor

https://www.geeksforgeeks.org/copy-constructor-in-cpp/

a member function that initializes an object using another object of the same class

copy constructor initializes new objects

## Assignation Operator Overload

assignment operator replaces the contents of existing objects

## Overloading

https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

C++ allows you to specify more than one definition for a function name or an operator in the same scope, which is called function overloading and operator overloading respectively.

An overloaded declaration is a declaration that is declared with the same name as a previously declared declaration in the same scope, except that both declarations have different arguments and obviously different definition (implementation).

## Static Member Functions

https://www.learncpp.com/cpp-tutorial/static-member-functions/

## Inheritance

https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm

can be public protected private

A derived class inherits all base class methods with the following exceptions −

Constructors, destructors and copy constructors of the base class.
Overloaded operators of the base class.
The friend functions of the base class.

## Default Constructors

https://en.cppreference.com/w/cpp/language/default_constructor

A default constructor is a constructor which can be called with no arguments (either defined with an empty parameter list, or with default arguments provided for every parameter).

## Initialisation Lists

https://www.cprogramming.com/tutorial/initialization-lists-c++.html

## Multiple Inheritence

https://www.geeksforgeeks.org/multiple-inheritance-in-c/

## Virtual Functions

https://en.cppreference.com/w/cpp/language/virtual


## Function Overriding

Function Overriding occurs when a derived class has a definition for one of the member functions of the base class.

## Abstract Class

An abstract class is a class that is designed to be specifically used as a base class.
It therefore cannot be called directly.
In c++ a class is abstract if it has at least one pure virtual member function.
A pure virtual function is a function that must be overridden in a derived class and need not be defined.
A virtual function is declared to be “pure” using the curious =0 syntax.

In animal.hpp change:
virtual void    makeSound() const;
to:
virtual void    makeSound() const = 0;


## Interfaces

It’s common to call pure abstract class Interface

https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm

## Public vs Private

The class members declared as private can be accessed only by the functions inside the class. 
The data members and member functions declared public can be accessed by other classes too.

https://www.geeksforgeeks.org/difference-between-public-and-private-in-c-with-example/

## Exceptions (classes)

https://rollbar.com/blog/cpp-custom-exceptions/

- create a custom class which inherits all properties from the std::exception class
- override the what() function from std::exception to return a custom error message
- in main, create a try-catch block to throw and handle the exception
-- in try block, create an object of MyCustomException and throw it
-- in catch block, print the custom message by accessing the what() function.

## Serialisation

https://isocpp.org/wiki/faq/serialization

## Reinterpret cast
Converts between types by reinterpreting the underlying bit pattern.
a compile-time directive which instructs the compiler to treat expression as if it had the type new-type.
https://en.cppreference.com/w/cpp/language/reinterpret_cast

just do:
reinterpret_case<int>

