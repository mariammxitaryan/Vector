#include "vectorIteratorHeader.hpp"

// ==================================================
// Constructor: Initializes the iterator with a pointer.
// ==================================================
template <typename T>
Iterator<T>::Iterator(pointer p) : data(p) {} 

// ==================================================
// Dereference operator: Returns a reference to the 
// object the iterator is pointing to.
// ==================================================
template <typename T>
typename Iterator<T>::reference Iterator<T>::operator*() const {
    return *data;
}

// ==================================================
// Arrow operator: Returns a pointer to the object 
// the iterator is pointing to.
// ==================================================
template <typename T>
typename Iterator<T>::pointer Iterator<T>::operator->() const {
    return data;
}

// ==================================================
// Pre-increment operator: Advances the iterator to 
// the next element and returns the updated iterator.
// ==================================================
template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    ++data;
    return *this;
}

// ==================================================
// Pre-decrement operator: Moves the iterator to the 
// previous element and returns the updated iterator.
// ==================================================
template <typename T>
Iterator<T>& Iterator<T>::operator--() {
    --data;
    return *this;
}

// ==================================================
// Post-increment operator: Returns a copy of the iterator
// before incrementing it.
// ==================================================
template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
    Iterator tmp = *this;
    ++data;
    return tmp;
}

// ==================================================
// Post-decrement operator: Returns a copy of the iterator 
// before decrementing it.
// ==================================================
template <typename T>
Iterator<T> Iterator<T>::operator--(int) {
    Iterator tmp = *this;
    --data;
    return tmp;
}

// ==================================================
// Addition operator: Returns a new iterator offset by 'n' 
// elements from the current position.
// ==================================================
template <typename T>
Iterator<T> Iterator<T>::operator+(difference_type n) const {
    return Iterator<T>(data + n);
}

// ==================================================
// Subtraction operator: Returns a new iterator offset by 
// '-n' elements from the current position.
// ==================================================
template <typename T>
Iterator<T> Iterator<T>::operator-(difference_type n) const {
    return Iterator<T>(data - n);
}

// ==================================================
// Difference operator: Returns the distance between two 
// iterators as the number of elements between them.
// ==================================================
template <typename T>
typename Iterator<T>::difference_type Iterator<T>::operator-(const Iterator<T>& other) const {
    return data - other.data;
}

// ==================================================
// Equality operator: Compares two iterators to check if they
// point to the same element.
// ==================================================
template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& other) const {
    return data == other.data;
}

// ==================================================
// Inequality operator: Compares two iterators to check if 
// they point to different elements.
// ==================================================
template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const {
    return !(data == other.data);
}

// ==================================================
// Less-than operator: Compares two iterators to check if 
// the current iterator is positioned before another.
// ==================================================
template <typename T>
bool Iterator<T>::operator<(const Iterator<T>& other) const {
    return data < other.data;
}

// ==================================================
// Greater-than operator: Compares two iterators to check if 
// the current iterator is positioned after another.
// ==================================================
template <typename T>
bool Iterator<T>::operator>(const Iterator<T>& other) const {
    return data > other.data;
}

// ==================================================
// Less-than or equal to operator: Compares two iterators 
// to check if the current iterator is positioned before or
// at the same position as another.
// ==================================================
template <typename T>
bool Iterator<T>::operator<=(const Iterator<T>& other) const {
    return data <= other.data;
}

// ==================================================
// Greater-than or equal to operator: Compares two iterators
// to check if the current iterator is positioned after or
// at the same position as another.
// ==================================================
template <typename T>
bool Iterator<T>::operator>=(const Iterator<T>& other) const {
    return data >= other.data;
}

// ==================================================
// Subscript operator: Provides direct access to the element 
// at a specific index, both for read and write operations.
// ==================================================
template <typename T>
typename Iterator<T>::reference Iterator<T>::operator[](size_t index) {
    return data[index];
}

// ==================================================
// Const subscript operator: Provides read-only access to 
// the element at a specific index.
// ==================================================
template <typename T>
typename Iterator<T>::reference Iterator<T>::operator[](size_t index) const {
    return data[index];
}
