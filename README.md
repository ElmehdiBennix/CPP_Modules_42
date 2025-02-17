# CPP_Modules_42

Welcome to a comprehensive guide on C++98 fundamentals and Object-Oriented Programming. This repository contains modules designed to help you understand the core concepts of C++ and its distinctions from C programming.

## Table of Contents

- [CPP\_Modules\_42](#cpp_modules_42)
  - [Table of Contents](#table-of-contents)
  - [Introduction to C++98](#introduction-to-c98)
  - [Core Language Features](#core-language-features)
    - [Namespaces](#namespaces)
    - [Input/Output Streams](#inputoutput-streams)
    - [References vs Pointers](#references-vs-pointers)
    - [Type Casting](#type-casting)
  - [Object-Oriented Programming](#object-oriented-programming)
    - [Classes and Objects](#classes-and-objects)
    - [Constructors and Destructors](#constructors-and-destructors)
    - [Member Functions](#member-functions)
  - [Advanced OOP Concepts](#advanced-oop-concepts)
    - [Inheritance](#inheritance)
    - [Polymorphism](#polymorphism)
    - [Encapsulation](#encapsulation)
    - [Abstraction](#abstraction)
    - [Memory Management](#memory-management)
    - [Exception Handling](#exception-handling)
  - [Templates and Generic Programming](#templates-and-generic-programming)
    - [Function Templates](#function-templates)
    - [Class Templates](#class-templates)
    - [Template Specialization](#template-specialization)
    - [Best Practices](#best-practices)
    - [Practical Example](#practical-example)
  - [Standard Template Library (STL)](#standard-template-library-stl)
    - [Containers](#containers)
    - [Algorithms](#algorithms)
    - [Iterators](#iterators)
  - [Best Practices](#best-practices-1)
  - [Contributing](#contributing)

## Introduction to C++98

C++98 represents the first standardized version of C++, ratified in 1998. Created by Bjarne Stroustrup, it extends C by adding object-oriented features while maintaining backward compatibility. This standard forms the foundation of modern C++ programming and remains relevant for understanding core language concepts.

Key features introduced in C++98:
- Object-oriented programming support
- Template programming
- Standard Template Library (STL)
- Exception handling
- Reference types
- Overloading

## Core Language Features

### Namespaces

Namespaces solve the problem of name collisions in large software projects. Think of them as last names for code elements - just as multiple people can share a first name but be distinguished by their last names, different pieces of code can share names but be distinguished by their namespaces.

Namespaces serve several important purposes:
1. **Logical Grouping**: Related code elements can be grouped together under a meaningful name
2. **Avoiding Conflicts**: Different libraries can use the same names without interfering with each other
3. **Code Organization**: Large projects become more manageable when code is organized into namespaces

When you write:

```cpp
namespace Mathematics {
    double add(double a, double b) { return a + b; }
}

// Usage
double sum = Mathematics::add(3.14, 2.71);
```

You're creating a named scope where names won't conflict with similar names in other namespaces. This becomes crucial in large projects where multiple teams might create functions with similar names for different purposes.

### Input/Output Streams

C++98 revolutionized input/output operations through streams, providing a type-safe and extensible way to handle I/O operations. Unlike C's printf and scanf, C++ streams:

1. **Are Type-Safe**: The compiler checks that the types match, preventing many common errors
2. **Are Extensible**: You can define I/O operations for your own types
3. **Handle Memory Automatically**: No need to specify buffer sizes or format strings
4. **Support Chaining**: Operations can be combined using the << and >> operators

The stream system is built around several key classes:
- `istream`: Handles input operations
- `ostream`: Handles output operations
- `iostream`: Combines input and output capabilities
- `fstream`: Provides file I/O operations

```cpp
#include <iostream>

std::string name;
std::cout << "Enter your name: ";
std::cin >> name;
std::cout << "Hello, " << name << "!" << std::endl;
```

### References vs Pointers

References represent one of C++'s most important improvements over C. While pointers and references might seem similar, they serve different purposes and have distinct characteristics:

References are:
1. **Always Valid**: Must be initialized when declared
2. **Cannot be Null**: Always refer to some object
3. **Cannot be Reassigned**: Once bound, always refer to the same object
4. **More Intuitive Syntax**: Use normal object syntax (dot notation)

Pointers are:
1. **Can be Null**: Might not point to any valid object
2. **Can be Reassigned**: Can point to different objects
3. **Require Explicit Dereferencing**: Use -> or * operator
4. **Support Pointer Arithmetic**: Can perform address calculations

Choose references when:
- You know the reference will always be valid
- You want to prevent null values
- You're passing parameters that you don't want to modify
- You want cleaner, more intuitive syntax

Choose pointers when:
- You need to represent "no object" (null)
- You need to change what is being pointed to
- You need pointer arithmetic
- You're working with arrays or dynamic memory


```cpp
void modifyValue(int& value) {    // Using reference
    value *= 2;
}

void modifyPointer(int* value) {  // Using pointer
    if (value) {                  // Requires null check
        *value *= 2;
    }
}
```

### Type Casting

C++98 introduced a new casting system to make type conversions more explicit and safer. Unlike C-style casts, C++ provides four distinct casting operators, each with specific purposes:

Casting operators:
- `static_cast<>`: General-purpose casting
- `dynamic_cast<>`: Safe downcasting of polymorphic objects
- `const_cast<>`: Casting away const/volatile
- `reinterpret_cast<>`: Low-level reinterpreting of bit patterns

1. **static_cast**
   - Used for straightforward type conversions
   - Performs compile-time checking
   - Cannot remove const or volatile qualifiers
   - Example: Converting between numeric types or up/down class hierarchy

2. **dynamic_cast**
   - Used for safe downcasting in inheritance hierarchies
   - Performs runtime type checking
   - Returns null (for pointers) or throws exception (for references) if cast fails
   - Requires RTTI (Run-Time Type Information)

3. **const_cast**
   - Used to remove or add const/volatile qualifiers
   - Should be used sparingly as it can break const correctness
   - Primarily used when dealing with legacy APIs

4. **reinterpret_cast**
   - Used for low-level reinterpretation of bit patterns
   - Most dangerous cast - use with extreme caution
   - Typically used for system-level programming

```cpp
double pi = 3.14159;
int rounded = static_cast<int>(pi);  // Explicit conversion
```

## Object-Oriented Programming

### Classes and Objects

Classes are the cornerstone of object-oriented programming in C++. A class combines:

1. **Data Members** (Attributes):
   - Variables that store the object's state
   - Can be of any type, including other classes
   - Usually private to maintain encapsulation

2. **Member Functions** (Methods):
   - Functions that define the object's behavior
   - Can access and modify the object's data members
   - Define the interface for interacting with objects

3. **Access Control**:
   - private: Only accessible within the class
   - protected: Accessible within the class and its derivatives
   - public: Accessible from anywhere

Classes provide several key benefits:
- **Encapsulation**: Combining data and behavior
- **Information Hiding**: Protecting internal details
- **Abstraction**: Presenting a simplified interface
- **Reusability**: Creating reusable components

```cpp
class BankAccount {
private:
    double balance;
    std::string accountHolder;

public:
    BankAccount(const std::string& holder, double initial = 0.0)
        : balance(initial), accountHolder(holder) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }
};
```

### Constructors and Destructors

Constructors and destructors manage an object's lifecycle, ensuring proper initialization and cleanup:

Proper resource management through constructors and destructors is crucial in C++98:

**Constructors**:
1. **Default Constructor**: Creates object with default values
2. **Parameterized Constructor**: Creates object with specified values
3. **Copy Constructor**: Creates object as copy of another
4. **Assignment Operator**: Copies one object to another

**Constructors handle**:
- Memory allocation
- Member initialization
- Resource acquisition
- Setting initial state

**Destructors handle**:
- Clean up resources
- Release memory
- Close files or connections
- Ensure no resource leaks

```cpp
class ResourceManager {
private:
    int* data;

public:
    // Constructor
    ResourceManager() : data(new int[100]) {
        // Initialize resource
    }

    // Copy constructor
    ResourceManager(const ResourceManager& other) : data(new int[100]) {
        // Deep copy data from other
    }

    // Destructor
    ~ResourceManager() {
        delete[] data;  // Clean up resource
    }
};
```

### Member Functions

Member functions define the behavior of a class and come in several varieties, each serving a specific purpose in object-oriented design. Understanding these different types of member functions is crucial for effective C++ programming.

**Regular Member Functions**
These are the most common type of member functions. They can access and modify the object's state and represent the object's behaviors.

```cpp
class Counter {
private:
    int count;

public:
    // Regular member function
    void increment() {
        count++;  // Can access and modify class members
    }

    // Regular member function with parameters
    void add(int value) {
        count += value;
    }
};
```

**Const Member Functions**
Const member functions guarantee they won't modify the object's state. This is crucial for:
- Documenting which operations are safe
- Allowing functions to work with const objects
- Preventing accidental modifications

```cpp
class BankAccount {
private:
    double balance;

public:
    // Const member function - promises not to modify the object
    double getBalance() const {
        return balance;  // Only reads, doesn't modify
    }

    // Non-const function - can modify the object
    void deposit(double amount) {
        balance += amount;  // Modifies the object's state
    }
};
```

**Static Member Functions**
Static member functions belong to the class itself rather than any specific instance. They:
- Can't access non-static members
- Don't have a 'this' pointer
- Can be called without creating an object
- Are shared by all instances of the class

```cpp
class MathOperations {
private:
    static int operationCount;  // Shared by all instances

public:
    // Static member function
    static int square(int x) {
        operationCount++;  // Can access static members
        return x * x;
    }

    // Static function to get operation count
    static int getOperationCount() {
        return operationCount;
    }
};

// Don't forget to define static members
int MathOperations::operationCount = 0;
```

**Virtual Functions**
Virtual functions enable runtime polymorphism, allowing derived classes to override base class behavior. They form the foundation of dynamic behavior in C++.

```cpp
class Shape {
public:
    // Virtual function - can be overridden by derived classes
    virtual double area() const {
        return 0.0;  // Default implementation
    }

    // Pure virtual function - must be overridden
    virtual double perimeter() const = 0;

    // Virtual destructor - essential for proper cleanup
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Override of virtual function
    double area() const override {
        return 3.14159 * radius * radius;
    }

    // Implementation of pure virtual function
    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
};
```

## Advanced OOP Concepts

### Inheritance

Inheritance is a fundamental mechanism in C++ that allows you to create new classes based on existing ones. It enables:
- Code reuse
- Establishment of class hierarchies
- Implementation of "is-a" relationships
- Extension of existing functionality

There are three types of inheritance in C++:
1. **Public Inheritance**: Most common, represents "is-a" relationship
2. **Protected Inheritance**: Rare, used for implementation inheritance
3. **Private Inheritance**: Represents "implemented-in-terms-of" relationship

```cpp
// Base class
class Animal {
protected:  // Accessible by derived classes
    std::string name;
    int age;

public:
    Animal(const std::string& n, int a) : name(n), age(a) {}

    virtual void makeSound() const = 0;  // Pure virtual function

    void sleep() const {
        std::cout << name << " is sleeping" << std::endl;
    }
};

// Derived class with public inheritance
class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& n, int a, const std::string& b)
        : Animal(n, a), breed(b) {}

    // Implementing the pure virtual function
    void makeSound() const override {
        std::cout << name << " says: Woof!" << std::endl;
    }

    // Adding new functionality
    void fetch() const {
        std::cout << name << " is fetching the ball" << std::endl;
    }
};

// Usage example
int main() {
    Dog rex("Rex", 3, "German Shepherd");
    rex.makeSound();  // Calls Dog's version
    rex.sleep();      // Calls Animal's version
    rex.fetch();      // Dog-specific function
}
```

In this example:
- `Animal` is the base class providing common attributes and behaviors
- `Dog` inherits from `Animal`, adding specific behaviors
- The `protected` members in `Animal` are accessible in `Dog`
- `virtual` functions enable polymorphic behavior
- Constructor chaining ensures proper initialization

### Polymorphism

Polymorphism in C++ comes in two forms:

1. **Static (Compile-time) Polymorphism**
   - Function overloading
   - Operator overloading
   - Determined at compile time

2. **Dynamic (Runtime) Polymorphism**
   - Virtual functions
   - Inheritance
   - Determined at runtime

Here's a comprehensive example showcasing both types:

```cpp
class Calculator {
public:
    // Function overloading (Static polymorphism)
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    // Operator overloading
    Calculator operator+(const Calculator& other) {
        // Implementation here
        return *this;
    }
};
```

```cpp
// Base class for dynamic polymorphism
class Vehicle {
public:
    virtual void startEngine() = 0;
    virtual double calculateFuelEfficiency() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    double fuelCapacity;
    double mileage;

public:
    Car(double fc, double m) : fuelCapacity(fc), mileage(m) {}

    void startEngine() override {
        std::cout << "Car engine started" << std::endl;
    }

    double calculateFuelEfficiency() const override {
        return mileage / fuelCapacity;
    }
};

class ElectricCar : public Vehicle {
private:
    double batteryCapacity;
    double range;

public:
    ElectricCar(double bc, double r) : batteryCapacity(bc), range(r) {}

    void startEngine() override {
        std::cout << "Electric motor initialized" << std::endl;
    }

    double calculateFuelEfficiency() const override {
        return range / batteryCapacity;
    }
};

// Usage showing polymorphic behavior
void testVehicle(Vehicle& v) {
    v.startEngine();  // Calls appropriate version based on actual type
    std::cout << "Efficiency: " << v.calculateFuelEfficiency() << std::endl;
}
```
### Encapsulation

Encapsulation is one of the fundamental principles of object-oriented programming that combines data and methods that operate on that data within a single unit or object. It involves bundling the data with the methods that manipulate that data and restricting direct access to some of an object's components. This is like creating a protective shield around the object's internals.

The main benefits of encapsulation include:
- Data hiding (information hiding)
- Increased security of data
- Prevention of unauthorized access
- Making the interface simpler and reducing complexity

Here's a comprehensive example demonstrating encapsulation:

```cpp
class BankAccount {
private:
    // Private data members - encapsulated data
    double balance;
    std::string accountNumber;
    std::string pin;

    // Private helper method
    bool validatePin(const std::string& inputPin) const {
        return pin == inputPin;
    }

public:
    // Constructor initializes the encapsulated data
    BankAccount(const std::string& accNum, const std::string& initialPin)
        : balance(0.0), accountNumber(accNum), pin(initialPin) {}

    // Public interface methods to interact with private data
    bool deposit(double amount, const std::string& inputPin) {
        if (!validatePin(inputPin)) {
            std::cout << "Invalid PIN" << std::endl;
            return false;
        }

        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount, const std::string& inputPin) {
        if (!validatePin(inputPin)) {
            std::cout << "Invalid PIN" << std::endl;
            return false;
        }

        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Getter method with restricted information
    double getBalance(const std::string& inputPin) const {
        if (!validatePin(inputPin)) {
            std::cout << "Invalid PIN" << std::endl;
            return -1;
        }
        return balance;
    }

    // Public method to get partial account number
    std::string getDisplayAccountNumber() const {
        // Only shows last 4 digits
        return "XXXX-XXXX-" + accountNumber.substr(accountNumber.length() - 4);
    }
};

// Usage example
int main() {
    BankAccount account("1234567890", "1234");

    // Interact with the account through its public interface
    account.deposit(1000.0, "1234");
    std::cout << "Balance: " << account.getBalance("1234") << std::endl;
    std::cout << "Account: " << account.getDisplayAccountNumber() << std::endl;

    // Direct access to private members is not possible:
    // account.balance = 1000000.0;  // Compilation error
    // std::cout << account.pin;     // Compilation error
}
```

### Abstraction

Abstraction is the process of hiding complex implementation details and showing only the necessary features of an object. It helps manage complexity by hiding unnecessary details and exposing only relevant features. Think of it as creating a simplified view of an object that includes only what's essential for other code to know.

Abstraction in C++ can be achieved through:
1. Abstract classes (using pure virtual functions)
2. Interfaces (using pure virtual functions with no data members)
3. Well-defined public interfaces

Here's an example demonstrating abstraction:

```cpp
// Abstract base class representing a generic payment method
class PaymentMethod {
public:
    virtual bool processPayment(double amount) = 0;  // Pure virtual function
    virtual std::string getPaymentType() const = 0;
    virtual ~PaymentMethod() {}  // Virtual destructor
};

// Concrete implementation for credit card payments
class CreditCardPayment : public PaymentMethod {
private:
    std::string cardNumber;
    std::string expiryDate;
    std::string cvv;

    // Complex implementation details hidden from users
    bool validateCard() const {
        // Complex validation logic
        return true;  // Simplified for example
    }

    bool connectToPaymentGateway() const {
        // Complex network communication
        return true;  // Simplified for example
    }

public:
    CreditCardPayment(const std::string& card, const std::string& expiry,
                      const std::string& cv)
        : cardNumber(card), expiryDate(expiry), cvv(cv) {}

    // Implementation of abstract methods
    bool processPayment(double amount) override {
        // Users don't need to know the complex steps involved
        if (!validateCard()) return false;
        if (!connectToPaymentGateway()) return false;

        // Process the payment
        std::cout << "Processing credit card payment of $"
                  << amount << std::endl;
        return true;
    }

    std::string getPaymentType() const override {
        return "Credit Card";
    }
};

// Another concrete implementation for PayPal
class PayPalPayment : public PaymentMethod {
private:
    std::string email;
    std::string password;

    bool authenticateUser() const {
        // Complex authentication logic
        return true;  // Simplified for example
    }

public:
    PayPalPayment(const std::string& em, const std::string& pwd)
        : email(em), password(pwd) {}

    bool processPayment(double amount) override {
        if (!authenticateUser()) return false;

        std::cout << "Processing PayPal payment of $"
                  << amount << std::endl;
        return true;
    }

    std::string getPaymentType() const override {
        return "PayPal";
    }
};

// Example usage demonstrating abstraction
class OnlineStore {
public:
    void checkout(PaymentMethod& payment, double amount) {
        // The store doesn't need to know the specific payment type
        // or how it processes payments
        if (payment.processPayment(amount)) {
            std::cout << "Payment successful using "
                      << payment.getPaymentType() << std::endl;
        } else {
            std::cout << "Payment failed" << std::endl;
        }
    }
};

int main() {
    CreditCardPayment creditCard("1234-5678-9012-3456", "12/25", "123");
    PayPalPayment payPal("user@email.com", "password");

    OnlineStore store;
    store.checkout(creditCard, 99.99);
    store.checkout(payPal, 49.99);
}
```

In this example:
- The `PaymentMethod` abstract class defines a common interface for all payment methods
- Specific payment implementations hide their complex details
- The `OnlineStore` class works with the abstracted `PaymentMethod` interface, not caring about the specific implementation
- Users of the payment classes don't need to know how payments are processed internally

These concepts of encapsulation and abstraction work together with polymorphism to create more maintainable and robust code:
- Encapsulation protects the data and implementation details
- Abstraction simplifies the interface and hides complexity
- Polymorphism allows different implementations to be used interchangeably

This combination of principles enables the creation of flexible, maintainable, and secure object-oriented systems.

### Memory Management

Memory management in C++98 requires careful attention as it's handled manually. Understanding how memory works in C++ is crucial for writing efficient and leak-free programs.

**Stack vs Heap Memory**
C++ uses two main types of memory:

1. **Stack Memory**
   - Automatically managed
   - Fixed size
   - Very fast access
   - Deallocated when variables go out of scope
   - Used for local variables and function parameters

2. **Heap Memory**
   - Manually managed
   - Dynamic size
   - Slower than stack memory
   - Must be explicitly deallocated
   - Used for dynamic allocation

Here's how memory management works in practice:

```cpp
class DynamicArray {
private:
    int* data;
    size_t size;

public:
    // Constructor - allocates memory
    DynamicArray(size_t n) : size(n) {
        data = new int[size];  // Allocate heap memory
        for (size_t i = 0; i < size; i++) {
            data[i] = 0;  // Initialize all elements
        }
    }

    // Destructor - frees memory
    ~DynamicArray() {
        delete[] data;  // Free heap memory
    }

    // Copy constructor - deep copy
    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];  // Allocate new memory
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];  // Copy elements
        }
    }

    // Assignment operator - deep copy
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {  // Check for self-assignment
            delete[] data;  // Free old memory
            size = other.size;
            data = new int[size];  // Allocate new memory
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];  // Copy elements
            }
        }
        return *this;
    }

    // Accessor methods
    int& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        return data[index];
    }
};
```

**Memory Management Best Practices:**

1. **RAII (Resource Acquisition Is Initialization)**
   - Resources should be acquired in constructors
   - Resources should be released in destructors
   - This ensures automatic cleanup when objects go out of scope

```cpp
class FileHandler {
private:
    std::FILE* file;

public:
    FileHandler(const char* filename) {
        file = std::fopen(filename, "r");
        if (!file) throw std::runtime_error("Could not open file");
    }

    ~FileHandler() {
        if (file) {
            std::fclose(file);
        }
    }
};
```

2. **Rule of Three**
If a class requires a custom implementation of any of these, it typically needs all three:
   - Destructor
   - Copy constructor
   - Copy assignment operator

### Exception Handling

Exception handling provides a structured way to deal with runtime errors in C++98. It allows you to separate error-handling code from normal program logic.

**Exception Handling Components:**

1. **try Block**
   - Contains code that might throw an exception
   - Can contain multiple statements

2. **catch Block**
   - Handles exceptions thrown in the try block
   - Can have multiple catch blocks for different exception types

3. **throw Statement**
   - Signals that an error has occurred
   - Can throw any type of object

Here's a comprehensive example:

```cpp
class DatabaseConnection {
private:
    bool isConnected;
    std::string connectionString;

public:
    // Custom exception classes
    class ConnectionError : public std::exception {
        std::string message;
    public:
        ConnectionError(const std::string& msg) : message(msg) {}
        const char* what() const throw() {
            return message.c_str();
        }
    };

    class QueryError : public std::exception {
        std::string message;
    public:
        QueryError(const std::string& msg) : message(msg) {}
        const char* what() const throw() {
            return message.c_str();
        }
    };

    // Constructor might throw
    DatabaseConnection(const std::string& connStr)
        : connectionString(connStr), isConnected(false) {
        if (!connect()) {
            throw ConnectionError("Failed to connect to database");
        }
    }

    bool connect() {
        // Simulation of connection logic
        if (connectionString.empty()) {
            return false;
        }
        isConnected = true;
        return true;
    }

    void executeQuery(const std::string& query) {
        if (!isConnected) {
            throw ConnectionError("Not connected to database");
        }
        if (query.empty()) {
            throw QueryError("Empty query string");
        }
        // Query execution logic here
    }
};

// Usage example with exception handling
void performDatabaseOperations() {
    try {
        DatabaseConnection db("server=localhost;user=root");

        try {
            db.executeQuery("SELECT * FROM users");
        }
        catch (const DatabaseConnection::QueryError& e) {
            std::cerr << "Query error: " << e.what() << std::endl;
            // Handle query-specific error
        }
    }
    catch (const DatabaseConnection::ConnectionError& e) {
        std::cerr << "Connection error: " << e.what() << std::endl;
        // Handle connection-specific error
    }
    catch (const std::exception& e) {
        std::cerr << "General error: " << e.what() << std::endl;
        // Handle any other standard exceptions
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        // Handle any other exceptions
    }
}
```

**Exception Handling Best Practices:**

1. **Exception Safety Guarantees**
   - Basic Guarantee: Objects remain in valid state
   - Strong Guarantee: Operations are atomic (all-or-nothing)
   - No-throw Guarantee: Operations never throw

2. **Resource Management**
   - Use RAII to ensure resources are properly cleaned up
   - Destructors should never throw exceptions
   - Clean up resources in reverse order of acquisition


## Templates and Generic Programming

Templates in C++98 enable type-independent programming while maintaining type safety at compile time. They allow you to write code that works with any data type, forming the foundation of generic programming.

### Function Templates

Function templates allow a single function definition to work with multiple data types. The compiler generates appropriate functions for each type when used:

```cpp
// Basic function template
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Template with multiple types
template<typename T, typename U>
bool isGreater(const T& value1, const U& value2) {
    return value1 > value2;
}

// Usage
int maxInt = maximum(10, 20);              // Works with integers
double maxDouble = maximum(3.14, 2.718);   // Works with doubles
bool result = isGreater(10, 5.5);         // Comparing different types
```

### Class Templates

Class templates enable creating classes that work with different data types, essential for implementing generic containers and data structures:

```cpp
template<typename T>
class Container {
private:
    T* data;
    size_t size;

public:
    explicit Container(size_t n) : size(n) {
        data = new T[size];
    }

    ~Container() {
        delete[] data;
    }

    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    size_t getSize() const { return size; }
};

// Usage
Container<int> numbers(5);
Container<std::string> words(3);
```

### Template Specialization

Template specialization provides different implementations for specific types while maintaining the generic interface:

```cpp
// Primary template
template<typename T>
class DataHandler {
public:
    static void process(const T& data) {
        std::cout << "Processing generic data: " << data << std::endl;
    }
};

// Specialization for strings
template<>
class DataHandler<std::string> {
public:
    static void process(const std::string& data) {
        std::cout << "Processing string of length: " << data.length() << std::endl;
    }
};

// Usage
DataHandler<int>::process(42);
DataHandler<std::string>::process("Hello");
```

### Best Practices

When working with templates:

1. Document type requirements clearly
2. Use meaningful template parameter names
3. Consider compilation time and code bloat
4. Provide specialized implementations for better performance
5. Use static assertions to catch errors at compile-time

### Practical Example

Here's a complete example showing templates in action:

```cpp
template<typename T>
class SimpleVector {
private:
    T* elements;
    size_t capacity;
    size_t count;

    void grow() {
        capacity *= 2;
        T* temp = new T[capacity];
        for (size_t i = 0; i < count; ++i) {
            temp[i] = elements[i];
        }
        delete[] elements;
        elements = temp;
    }

public:
    SimpleVector() : capacity(10), count(0) {
        elements = new T[capacity];
    }

    ~SimpleVector() {
        delete[] elements;
    }

    void push_back(const T& element) {
        if (count == capacity) {
            grow();
        }
        elements[count++] = element;
    }

    T& operator[](size_t index) {
        if (index >= count) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    size_t size() const { return count; }
};

// Usage example
int main() {
    SimpleVector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    SimpleVector<std::string> words;
    words.push_back("Hello");
    words.push_back("World");

    // Access elements
    std::cout << numbers[0] << std::endl;  // Prints: 1
    std::cout << words[1] << std::endl;    // Prints: World

    return 0;
}
```

Templates enable you to write flexible, reusable code while maintaining type safety and performance. They are fundamental to modern C++ programming and form the basis for the Standard Template Library (STL).

## Standard Template Library (STL)

The Standard Template Library represents one of C++98's most powerful features, providing a collection of template classes and functions that implement commonly used data structures and algorithms. Understanding the STL is crucial because it offers efficient, tested implementations that save development time and reduce errors.

### Containers

Containers in the STL store and organize data in different ways, each optimized for specific use cases. Let's explore the main types:

**Sequence Containers**
These containers store elements in a linear sequence, much like items on a shelf:

1. **Vector**
The vector is the most commonly used container, providing dynamic array functionality with automatic memory management.

```cpp
#include <vector>

class VectorExample {
public:
    void demonstrateVector() {
        // Creating and initializing a vector
        std::vector<int> numbers;

        // Adding elements
        numbers.push_back(1);    // Adds to end
        numbers.push_back(2);
        numbers.push_back(3);

        // Accessing elements
        int firstElement = numbers[0];          // Direct access
        int lastElement = numbers.back();       // Last element

        // Iterating through elements
        for (std::vector<int>::iterator it = numbers.begin();
             it != numbers.end(); ++it) {
            std::cout << *it << " ";
        }

        // Size and capacity
        size_t size = numbers.size();           // Number of elements
        size_t capacity = numbers.capacity();   // Allocated space

        // Resizing
        numbers.resize(5);      // Grows to size 5, new elements are 0
        numbers.reserve(10);    // Reserves space for 10 elements
    }
};
```

2. **List**
A doubly-linked list allowing efficient insertions and deletions at any position:

```cpp
#include <list>

class ListExample {
public:
    void demonstrateList() {
        std::list<std::string> names;

        // Adding elements
        names.push_back("Alice");    // Add to end
        names.push_front("Bob");     // Add to beginning

        // Insert in middle
        std::list<std::string>::iterator it = names.begin();
        ++it;  // Move to second position
        names.insert(it, "Charlie");

        // Removing elements
        names.pop_front();          // Remove first
        names.pop_back();           // Remove last

        // Splicing lists
        std::list<std::string> otherNames;
        otherNames.push_back("David");
        names.splice(names.end(), otherNames);  // Move elements from otherNames
    }
};
```

**Associative Containers**
These containers automatically sort and organize elements based on keys:

1. **Map**
Stores key-value pairs, sorted by key:

```cpp
#include <map>

class MapExample {
public:
    void demonstrateMap() {
        std::map<std::string, int> ages;

        // Inserting elements
        ages["Alice"] = 25;
        ages.insert(std::make_pair("Bob", 30));

        // Accessing elements
        int aliceAge = ages["Alice"];    // Direct access

        // Checking if key exists
        if (ages.find("Charlie") != ages.end()) {
            std::cout << "Charlie's age is known" << std::endl;
        }

        // Iterating through map
        for (std::map<std::string, int>::const_iterator it = ages.begin();
             it != ages.end(); ++it) {
            std::cout << it->first << " is " << it->second
                      << " years old" << std::endl;
        }
    }
};
```

2. **Set**
Stores unique elements in sorted order:

```cpp
#include <set>

class SetExample {
public:
    void demonstrateSet() {
        std::set<int> uniqueNumbers;

        // Inserting elements
        uniqueNumbers.insert(3);
        uniqueNumbers.insert(1);
        uniqueNumbers.insert(4);
        uniqueNumbers.insert(1);  // Duplicate, won't be inserted

        // Checking for elements
        bool exists = uniqueNumbers.count(3) > 0;

        // Finding elements
        std::set<int>::iterator it = uniqueNumbers.find(4);
        if (it != uniqueNumbers.end()) {
            std::cout << "Found: " << *it << std::endl;
        }
    }
};
```

### Algorithms

The STL provides a rich set of algorithms that work with containers through iterators. These algorithms are template functions that operate independently of the container type:

```cpp
#include <algorithm>
#include <vector>

class AlgorithmsExample {
public:
    void demonstrateAlgorithms() {
        std::vector<int> numbers;
        for (int i = 1; i <= 5; ++i) {
            numbers.push_back(i);
        }

        // Finding elements
        std::vector<int>::iterator it =
            std::find(numbers.begin(), numbers.end(), 3);

        // Sorting
        std::sort(numbers.begin(), numbers.end());

        // Counting elements
        int count = std::count_if(numbers.begin(), numbers.end(),
            IsEven());  // Custom predicate

        // Transforming elements
        std::transform(numbers.begin(), numbers.end(),
                      numbers.begin(),
                      MultiplyByTwo());  // Custom function object
    }

private:
    // Function object (functor) for counting
    struct IsEven {
        bool operator()(int n) const {
            return n % 2 == 0;
        }
    };

    // Function object for transformation
    struct MultiplyByTwo {
        int operator()(int n) const {
            return n * 2;
        }
    };
};
```

### Iterators

Iterators provide a uniform way to access elements in containers, acting as a bridge between containers and algorithms:

```cpp
class IteratorExample {
public:
    void demonstrateIterators() {
        std::vector<int> numbers(5, 10);  // Vector of 5 tens

        // Different types of iterators
        std::vector<int>::iterator it;           // Read-write iterator
        std::vector<int>::const_iterator cit;    // Read-only iterator
        std::vector<int>::reverse_iterator rit;  // Reverse iterator

        // Forward iteration
        for (it = numbers.begin(); it != numbers.end(); ++it) {
            *it += 1;  // Modify elements
        }

        // Const iteration
        for (cit = numbers.begin(); cit != numbers.end(); ++cit) {
            std::cout << *cit << " ";  // Read-only access
        }

        // Reverse iteration
        for (rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
            std::cout << *rit << " ";  // Access in reverse order
        }
    }
};
```

## Best Practices

1. **Resource Management**
   - Always pair `new` with `delete`
   - Use constructors for initialization
   - Clean up resources in destructors
   - Implement the Rule of Three (destructor, copy constructor, copy assignment operator)

2. **Memory Safety**
   - Initialize all variables before use
   - Check for null pointers
   - Use references instead of pointers when possible
   - Avoid memory leaks through proper resource management

3. **Code Organization**
   - Use meaningful names for variables and functions
   - Keep functions small and focused
   - Document code with clear comments
   - Use consistent formatting

4. **Error Handling**
   - Use exceptions for error conditions
   - Handle resources properly in presence of exceptions
   - Document exceptions in function declarations

## Contributing

Feel free to contribute to this Readme by:
1. Forking the project
2. Creating your feature branch (`git checkout -b feature/AmazingFeature`)
3. Committing your changes (`git commit -m 'Add some AmazingFeature'`)
4. Pushing to the branch (`git push origin feature/AmazingFeature`)
5. Opening a Pull Request
