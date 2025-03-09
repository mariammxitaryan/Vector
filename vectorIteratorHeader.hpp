#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <iterator>
#include <memory>

template <typename T>
class Iterator{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
private: 
    pointer data;
public:
    explicit Iterator(pointer); 
    reference operator*();
    pointer operator->();
    Iterator& operator++();
    Iterator& operator--();
    Iterator operator++(int);
    Iterator& operator--(int);
    Iterator operator+(difference_type) const;
    Iterator operator-(difference_type) const;
    difference_type operator-(const Iterator&);
    bool operator==(const Iterator&) const;
    bool operator!=(const Iterator&) const;
    bool operator<(const Iterator&) const;
    bool operator>(const Iterator&) const;
    bool operator<=(const Iterator&) const;
    bool operator>=(const Iterator&) const;
    reference operator[](size_t);
    reference operator[](size_t) const;
};

#include "vectorIteratorImplementation.tpp"

#endif