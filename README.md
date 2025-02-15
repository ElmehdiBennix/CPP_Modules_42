# CPP_Modules_42
C++ modules designed to help you understand the specifities of the language when compared to C. Time to dive into Object Oriented Programming!

- [CPP\_Modules\_42](#cpp_modules_42)
  - [Introduction to C++98 - Concepts \& OOP](#introduction-to-c98---concepts--oop)
  - [Namespaces](#namespaces)
  - [Classes and Objects](#classes-and-objects)
  - [Overloading](#overloading)
  - [Memory Management](#memory-management)
  - [Exception Handling:](#exception-handling)
  - [Object-Oriented Programming (OOP) Concepts](#object-oriented-programming-oop-concepts)
    - [Encapsulation](#encapsulation)
    - [Inheritance](#inheritance)
    - [Polymorphism](#polymorphism)
    - [Abstraction](#abstraction)
  - [Template Programming](#template-programming)
  - [STL (Standard Template Library)](#stl-standard-template-library)
  - [Best Practices in C++98](#best-practices-in-c98)
  - [C++98 and the Future](#c98-and-the-future)
  - [Conclusion](#conclusion)

---

## Introduction to C++98 - Concepts & OOP

C++98 is a version of the C++ programming language that was standardized in 1998. It was created by **Bjarne Stroustrup**, a Danish computer scientist, and laid the foundation for modern C++ development by introducing several key concepts such as classes, objects, and memory management, all within a relatively simpler framework compared to later versions of the language, for more information, visit the [Wikipedia page on C++](https://en.wikipedia.org/wiki/C%2B%2B).

## Namespaces
C++ introduces namespaces to avoid name conflicts by grouping classes, functions, and variables into named scopes.

## Classes and Objects

In C++98, classes are blueprints for creating objects (instances). A class defines attributes (variables) and behaviors (methods) that the objects will have. Additionally, C++98 supports **constructors** and **destructors** to initialize and clean up objects.

**Constructor**: A constructor is a special member function that is called automatically when an object of the class is created. It initializes the object (default).
**Destructor**: A destructor is a special member function called when an object is destroyed or goes out of scope. It is used to release resources or perform cleanup tasks.


## Overloading
static poly
Function Overloading: C++ allows multiple functions with the same name but different parameters (different signature).

Operator Overloading: C++ allows operators to be redefined for user-defined types, allowing objects to be manipulated in a more intuitive way.

## Memory Management

In C++98, dynamic memory allocation and deallocation are managed using the `new` and `delete` operators. These operators allow for memory to be allocated on the heap during runtime and deallocated when no longer needed.

```cpp
int* ptr = new int(10);  // Allocates memory and initializes it to 10
std::cout << *ptr << std::endl;  // Output: 10
delete ptr // Deallocate the memory address
```

Example for arrays:

```cpp
int* arr = new int[5];  // Allocates an array of 5 integers
delete[] arr;  // Deallocates memory for the array
```

## Exception Handling:
C++ supports exception handling through try, catch, and throw to manage runtime errors in a more structured way.

## Object-Oriented Programming (OOP) Concepts
### Encapsulation

Encapsulation is a key concept in Object-Oriented Programming (OOP), where data (variables) and methods (functions) are bundled together inside a class. It restricts direct access to some of the object's components, exposing only necessary parts of the class via a public interface.

$ Key Features:
- **Data Hiding**: Internal data is protected from direct access and can only be modified via public methods (getters and setters).
- **Public Interface**: Public methods provide a controlled way to interact with the object.
- **Private Implementation**: Class details and data are hidden from outside interference.

$ Offers
- **Data Protection**: Ensures controlled access to internal data.
- **Maintainability**: Changes to internal implementation don’t affect external code.
- **Error Prevention**: Ensures that only valid operations are performed.

$ Example:

```cpp
class Account {
private:
    double balance;

public:
    Account(double initialBalance) {
        balance = (initialBalance > 0) ? initialBalance : 0;
    }

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};
```

### Inheritance

Inheritance allows a class (derived class) to inherit attributes and methods from another class (base class). This promotes code reuse and creates a hierarchical relationship between classes.

$ Example:

```cpp
class Vehicle {
public:
    void move() {
        std::cout << "Vehicle is moving." << std::endl;
    }
};

class Car : public Vehicle {  // Car inherits from Vehicle
public:
    void honk() {
        std::cout << "Car is honking!" << std::endl;
    }
};
```
    Base Class: Vehicle defines common behaviors (e.g., move()).
    Derived Class: Car inherits the move() method from Vehicle and adds its own method honk().

A derived class can inherit and extend the functionality of a base class, reducing redundancy and promoting reuse.

C++ allows classes to inherit from more than one base class, though it can lead to complexities like the "diamond problem.

### Polymorphism
 dynamic
Polymorphism allows a derived class to provide its own implementation of a method that is already defined in its base class. This enables objects of different types to be treated as objects of a common base type, with the appropriate method being called based on the actual object type at runtime.

$ Example:

```cpp
class Animal {
public:
    virtual void sound() {  // Virtual function allows overriding in derived classes
        std::cout << "Some animal sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {  // Override base class method
        std::cout << "Woof!" << std::endl;
    }
};
```

Base Class: Animal defines a method sound() that can be overridden.
Derived Class: Dog overrides the sound() method to provide its own implementation.

Using virtual allows the method in the base class to be overridden by the derived class, achieving runtime polymorphism. When you call sound() on an object of type Animal, the correct method is called based on the actual object type (Dog in this case), not the declared type (Animal).

Example of Runtime Polymorphism:
```
Animal* animal = new Dog();
animal->sound();  // Output: Woof!
```

Polymorphism enables flexibility, allowing you to write more generic and reusable code.

### Abstraction

Abstraction is the concept of hiding complex implementation details and exposing only the essential features of an object. In C++, abstraction is achieved using abstract classes and pure virtual functions. An abstract class cannot be instantiated directly and is used as a base for derived classes.

$ Example:

```cpp
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function (makes Shape an abstract class)
};

class Circle : public Shape {
public:
    void draw() override {  // Implementing the pure virtual function
        std::cout << "Drawing a circle." << std::endl;
    }
};
```

Abstract Class: Shape contains a pure virtual function draw(), making it an abstract class. This class cannot be instantiated.
Pure Virtual Function: A pure virtual function is declared using = 0. It forces derived classes to implement this method.
Concrete Class: Circle implements the draw() method and can be instantiated.

Abstraction allows you to define common interfaces for different derived classes, ensuring that each class implements the necessary functionality, while hiding the complexity of the implementation from the user.

## Template Programming
 C++ allows the use of templates, which enable the writing of generic code. This feature allows functions and classes to operate with any data type.

## STL (Standard Template Library)
Although the full functionality of STL was standardized in C++98, the core components like containers (e.g., vector, list, map), iterators, and algorithms were introduced.

## Best Practices in C++98

1. **Use Proper Encapsulation**
   - Always hide implementation details by keeping data members private and providing public getter/setter functions. This ensures that the data is accessed and modified in a controlled manner.

2. **Minimize the Use of Pointers**
   - Prefer references (`&`) over pointers (`*`) when possible. This reduces the complexity of memory management and minimizes the risk of errors such as dangling pointers and memory leaks.

3. **Use RAII (Resource Acquisition Is Initialization)**
   - Always allocate and deallocate resources (like memory, file handles, etc.) in the constructor and destructor of a class. This ensures resources are automatically cleaned up when the object goes out of scope.

4. **Avoid Memory Leaks**
   - Ensure every `new` has a corresponding `delete`. C++98 does not have smart pointers, so manual memory management is required. Use `delete` to free dynamically allocated memory and avoid memory leaks.

5. **Prefer `const` Correctness**
   - Use `const` wherever possible, both for function parameters and member functions that don’t modify object state. This provides better safety and self-documenting code.

6. **Use References for Large Objects**
   - Pass large objects (like `std::vector` or `std::string`) by reference to avoid unnecessary copies. For constant data, pass by `const` reference to prevent modification.

7. **Avoid Global Variables**
   - Global variables can lead to hard-to-find bugs and hinder modularity. Use local variables or class members instead.

8. **Follow Consistent Naming Conventions**
   - Stick to a consistent naming scheme for classes, variables, functions, and other entities. A good convention is to use camelCase for variables and functions, and PascalCase for classes.

9. **Keep Functions Small and Focused**
   - Each function should ideally do one thing and do it well. If a function grows too large, break it down into smaller, more manageable pieces.

10. **Use `#define` and Constants Carefully**
    - Avoid overusing `#define` for constants. Use `const` or `enum` instead for type safety and better debugging.

11. **Error Handling with `try-catch`**
    - Although exception handling was introduced in C++98, it was not widely used. However, it’s still a good practice to use `try-catch` blocks to handle potential errors, especially when dealing with dynamic memory allocation or file I/O.

12. **Optimize Only When Necessary**
    - Avoid premature optimization. Focus on writing clear and maintainable code first, and optimize only when performance becomes an issue.

13. **Use the Standard Library**
    - Make use of the C++98 Standard Library (STL) for common tasks like sorting, searching, and container management. It saves time and provides well-tested solutions.

14. **Avoid Using `goto`**
    - `goto` can make the code harder to follow and maintain. Use structured programming techniques like loops and conditionals instead.

15. **Document Code Well**
    - Add meaningful comments and documentation, especially for complex or non-obvious logic. It helps both you and others who may maintain the code later.


## C++98 and the Future

While C++98 is an older standard, it laid the groundwork for the modern C++ language. However, newer versions (like C++11 and later) introduced a wealth of features, including smart pointers, lambda functions, and more powerful template capabilities.

## Conclusion

By focusing on the fundamental concepts of C++98 and Object-Oriented Programming, this guide provides a solid foundation for writing efficient, object-oriented code. Although C++98 is an older standard, mastering its core principles is crucial for working with legacy code and understanding the evolution of the language.
