#include "vectorHeader.hpp"

// ==================================================
// Default constructor: Initializes an empty vector 
// with size 0, capacity 0, and allocates space for 1 element.
// ==================================================
template<typename T>
Vector<T>::Vector() : m_size{0}, m_capacity{0}, m_ptr(new T[1]) {}

// ==================================================
// Copy constructor: Creates a new vector as a copy of 
// the given vector 'vec' with the same size, capacity, 
// and elements.
// ==================================================
template<typename T>
Vector<T>::Vector(const Vector<T>& vec) {
    m_size = vec.m_size;
    m_capacity = vec.m_capacity;
    m_ptr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_ptr[i] = vec.m_ptr[i];
    } 
}

// ==================================================
// Constructor with capacity: Initializes a vector with 
// the specified capacity, with an initial size of 0.
// ==================================================
template<typename T>
Vector<T>::Vector(size_t cap) : m_capacity(cap), m_size(0) {
    m_ptr = new T[m_capacity];
}

// ==================================================
// Destructor: Releases the allocated memory when the 
// vector is destroyed.
// ==================================================
template<typename T>
Vector<T>::~Vector() {
    if (m_ptr) {
        delete[] m_ptr;
    }
}

// ==================================================
// Get size: Returns the current number of elements 
// in the vector.
// ==================================================
template<typename T>
size_t Vector<T>::getsize() const {
    return m_size;
}

// ==================================================
// Get capacity: Returns the total capacity of the vector, 
// i.e., the maximum number of elements it can hold.
// ==================================================
template<typename T>
size_t Vector<T>::getcapacity() const {
    return m_capacity;
}

// ==================================================
// Assignment operator: Assigns the contents of the given 
// vector 'vec' to the current vector, performing deep copy.
// ==================================================
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec) {
    if (this != vec) {
        delete[] m_ptr;
        m_size = vec.m_size;
        m_capacity = vec.m_capacity;
        m_ptr = new T[m_capacity];
        for (int i = 0; i < m_size; ++i) {
            m_ptr[i] = vec.m_ptr[i];
        }
    } 
    return *this;
}

// ==================================================
// Move constructor: Transfers the resources from another 
// vector to the current one, leaving the other vector in 
// a valid but empty state.
// ==================================================
template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept : m_size(other.m_size), m_capacity(other.m_capacity), m_ptr(other.m_ptr) {
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_ptr = nullptr;
}

// ==================================================
// Move assignment operator: Transfers the resources from 
// another vector to the current one, ensuring proper cleanup 
// of any previously allocated memory.
// ==================================================
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
    if (this != &other) {
        delete[] m_ptr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_ptr = other.m_ptr;
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_ptr = nullptr;
    }
    return *this;
}

// ==================================================
// Subscript operator: Allows access to elements by index, 
// both for reading and writing.
// ==================================================
template <typename T>
typename Vector<T>::reference Vector<T>::operator[](int index) {
    return m_ptr[index];
}

// ==================================================
// 'At' method: Returns a reference to the element at 
// the specified index, with bounds checking.
// ==================================================
template <typename T>
typename Vector<T>::reference Vector<T>::at(size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Invalid index");
    }
    return m_ptr[index];
}

// ==================================================
// Front method: Returns a reference to the first element 
// in the vector, throwing an exception if the vector is empty.
// ==================================================
template <typename T>
typename Vector<T>::reference Vector<T>::front() {
    if (m_size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return m_ptr[0];
}

// ==================================================
// Back method: Returns a reference to the last element 
// in the vector, throwing an exception if the vector is empty.
// ==================================================
template <typename T>
typename Vector<T>::reference Vector<T>::back() {
    if (m_size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return m_ptr[m_size - 1];
}

// ==================================================
// Reserve method: Increases the vector’s capacity to hold 
// at least 'newCap' elements, without changing the size.
// ==================================================
template <typename T>
void Vector<T>::reserve(size_t newCap) {
    if (newCap > m_capacity) {
        T* newPtr = new T[newCap];
        for (size_t i = 0; i < m_size; ++i) {
            newPtr[i] = m_ptr[i];
        }
        delete[] m_ptr;
        m_ptr = newPtr;
    }
    m_capacity = newCap;
}

// ==================================================
// Resize method: Changes the size of the vector to 'newSize', 
// potentially expanding or shrinking it. If needed, capacity
// is also adjusted.
// ==================================================
template <typename T>
void Vector<T>::resize(size_t newSize) {
    if (newSize > m_capacity) {
        reserve(newSize);
    }
    m_size = newSize; 
}

// ==================================================
// Empty method: Returns true if the vector has no elements,
// otherwise returns false.
// ==================================================
template <typename T>
bool Vector<T>::empty() const {
    return m_size == 0;
}

// ==================================================
// Shrink to fit method: Reduces the capacity of the vector 
// to match its current size, freeing unused memory.
// ==================================================
template <typename T>
void Vector<T>::shrink_to_fit() {
    reserve(m_size);
}

// ==================================================
// Push back method: Adds a new element to the end of the 
// vector, expanding its capacity if necessary.
// ==================================================
template <typename T>
void Vector<T>::push_back(T elem) {
    if (m_size == m_capacity) {
        reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    }
    m_ptr[m_size++] = elem;
}

// ==================================================
// Pop back method: Removes the last element from the vector, 
// reducing its size.
// ==================================================
template <typename T>
void Vector<T>::pop_back() {
    if (!m_size) {
        std::cout << "Vector is empty\n";
        return;
    }
    --m_size;
}

// ==================================================
// Insert method: Inserts a new element at the specified 
// index, shifting elements to the right as needed.
// ==================================================
template <typename T>
void Vector<T>::insert(size_t index, T data) {
    if (index < 0 || index > m_size) {
        std::cout << "Invalid index\n";
        return;
    }
    if (m_capacity == m_size) {
        reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    }
    if (index == m_size) {
        push_back(data);
        return;
    }
    for (int i = m_size; i > index; --i) {
        m_ptr[i] = m_ptr[i - 1];
    }
    m_ptr[index] = data;
    ++m_size;
}

// ==================================================
// Erase method: Removes the element at the specified index 
// and shifts subsequent elements to the left.
// ==================================================
template <typename T>
void Vector<T>::erase(size_t index) {
    if (index < 0 || index >= m_size) {
        std::cout << "Invalid index\n";
        return;
    }
    for (int i = index; i < m_size - 1; ++i) {
        m_ptr[i] = m_ptr[i + 1];
    }
    --m_size;
}

// ==================================================
// Clear method: Removes all elements from the vector,
// leaving it empty.
// ==================================================
template <typename T>
void Vector<T>::clear() {
    m_size = 0;
}

// ==================================================
// Begin method: Returns an iterator to the first element 
// in the vector.
// ==================================================
template <typename T>
typename Vector<T>::iterator Vector<T>::begin() const {
    return iterator(m_ptr);
}

// ==================================================
// End method: Returns an iterator to one past the last 
// element in the vector.
// ==================================================
template <typename T>
typename Vector<T>::iterator Vector<T>::end() const {
    return iterator(m_ptr + m_size);
}

// ==================================================
// Const begin method: Returns a constant iterator to the 
// first element in the vector.
// ==================================================
template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const {
    return const_iterator(m_ptr);
}

// ==================================================
// Const end method: Returns a constant iterator to one 
// past the last element in the vector.
// ==================================================
template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const {
    return const_iterator(m_ptr + m_size);
}
