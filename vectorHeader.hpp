#ifndef VECTOR_H
#define VECTOR_H

#include "vectorIteratorHeader.hpp"

template <typename T>
class Vector{
public:
    using iterator = Iterator<T>;
    using reference = T&;
    using const_iterator = Iterator<const T>;

    Vector();
    explicit Vector(size_t);
    Vector(const Vector&);
    ~Vector();
    size_t getsize() const;
    size_t getcapacity() const;
    Vector& operator=(const Vector&);
    Vector(Vector&&) noexcept;
    Vector& operator=(Vector&&) noexcept;
    reference operator[](int);
    reference at(size_t);
    reference front();
    reference back();
    void reserve(size_t);
    void resize(size_t);
    bool empty() const;
    void shrink_to_fit();
    void push_back(T);
    void pop_back();
    void insert(size_t, T);
    void erase(size_t);
    void clear();
    iterator begin() const;
    iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

private:
    size_t m_capacity;
    size_t m_size;
    T* m_ptr;
};

#include "vectorImplementation.tpp"

#endif