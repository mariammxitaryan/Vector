```markdown
# **Custom Vector Class Implementation** :blue_book: 

A custom implementation of a dynamic array (vector) in C++ designed to mimic the behavior of the `std::vector` container. This project demonstrates the use of modern C++ features and best practices to manage dynamic memory allocation, object copying, and moving operations efficiently.

---

## **Table of Contents** :bookmark_tabs:

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [API Documentation](#api-documentation)

---

## **Features** :sparkles:

- **Dynamic Resizing**: Automatically grows and shrinks the underlying array as elements are added or removed.
- **Copy & Move Semantics**: Support for both copy and move constructors, as well as assignment operators.
- **Memory Management**: Manages memory dynamically, ensuring efficient usage.
- **Exception Handling**: Safely handles invalid operations, such as accessing elements out of bounds.
- **Iterator Support**: Full support for custom iterators (`begin()`, `end()`, `cbegin()`, `cend()`).

---

## **Installation** :package:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/vector-project.git
   ```

2. **Navigate to the project directory**:
   ```bash
   cd vector-project
   ```

3. **Compile the code** using your favorite C++ compiler:
   ```bash
   g++ -std=c++17 -o vector vectorMain.cpp
   ```

4. **Run the executable**:
   ```bash
   ./vector
   ```

---

## **Usage** :wrench:

To get started with using the `Vector` class, simply include `vectorHeader.hpp` and use it as shown below:

### **Example:**
```cpp
#include "vectorHeader.hpp"
#include <iostream>

int main() {
    // Create a Vector of integers
    Vector<int> vec;

    // Add elements using push_back
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // Access elements using operator[]
    std::cout << "First element: " << vec[0] << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;

    // Iterate over the vector using iterators
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

---

## **API Documentation** :book:

Here is a breakdown of the key functions available in the `Vector` class:

### **Constructor**:
- `Vector()`: Default constructor that initializes an empty vector.
- `Vector(size_t cap)`: Constructor that initializes a vector with a specified capacity.
- `Vector(const Vector<T>& vec)`: Copy constructor that creates a new vector from an existing one.
- `Vector(Vector<T>&& other) noexcept`: Move constructor to efficiently transfer resources.

### **Destructor**:
- `~Vector()`: Destructor that properly frees memory.

### **Member Functions**:
- `size_t getsize() const`: Returns the current size of the vector.
- `size_t getcapacity() const`: Returns the current capacity of the vector.
- `bool empty() const`: Returns `true` if the vector is empty, otherwise `false`.
- `void reserve(size_t newCap)`: Reserves memory to accommodate at least `newCap` elements.
- `void resize(size_t newSize)`: Resizes the vector to `newSize`.
- `void push_back(T elem)`: Adds an element to the end of the vector.
- `void pop_back()`: Removes the last element of the vector.
- `void insert(size_t index, T data)`: Inserts an element at the specified index.
- `void erase(size_t index)`: Removes the element at the specified index.
- `void clear()`: Clears the vector (sets size to 0).
- `void shrink_to_fit()`: Reduces the vector’s capacity to fit its size.

### **Element Access**:
- `reference operator[](int index)`: Accesses the element at the given index.
- `reference at(size_t index)`: Accesses the element at the given index with bounds checking.
- `reference front()`: Returns the first element.
- `reference back()`: Returns the last element.

### **Iterators**:
- `iterator begin() const`: Returns an iterator to the first element.
- `iterator end() const`: Returns an iterator to one past the last element.
- `const_iterator cbegin() const`: Returns a constant iterator to the first element.
- `const_iterator cend() const`: Returns a constant iterator to one past the last element.

---

## **Contributing** :hands:

We welcome contributions! If you would like to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature (`git checkout -b feature-name`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-name`).
5. Open a pull request.

---

## **Acknowledgments** :trophy:

- Thanks to the C++ community for providing valuable resources and tutorials to help improve this project.
- Inspiration from the `std::vector` in the C++ Standard Library.
```

---
