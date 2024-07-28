#ifndef ARRAYLIST_H
#define ARRAYLIST_H


#include "Arduino.h"
#include "Memory.h"

template<typename E>
class ArrayList {
protected:
    size_t _size, _capacity;
    E *_array;
    void grow(size_t minCapacity) {
        size_t newCapacity = _capacity + (_capacity >> 1);
        if (newCapacity < minCapacity)
            newCapacity = minCapacity;
        E *newArray = new E[newCapacity];
        arraycopy(_array, newArray, _size);
        _array = newArray;
        _capacity = newCapacity;
    }
    void ensureExplicitCapacity(size_t minCapacity) {
        if (minCapacity > _capacity)
            grow(minCapacity);
    }
    void ensureCapacityInternal(size_t minCapacity) { ensureExplicitCapacity(max(10, minCapacity)); }

public:
    explicit ArrayList(size_t initialCapacity = 10) :
        _size(0), _capacity(initialCapacity), _array(new E[initialCapacity]) {}
    ArrayList(E const *const initialArray, size_t size) : _size(size), _capacity(size), _array(new E[size]) {
        arraycopy(initialArray, _array, size);
    }
    ArrayList(const ArrayList<E> &other) : ArrayList(other._array, other._size) {}
    ~ArrayList() { delete[] _array; }
    int size() { return _size; }
    E const *toArray() { return _array; }
    void set(int index, const E &element) { _array[index] = element; }
    E get(int index) { return _array[index]; }
    void clear() {
        _array = new E[0];
        _size = _capacity = 0;
    }
    void add(E const *const elements, size_t size) {
        ensureCapacityInternal(_size + size);
        arraycopy(elements, _array, size, 0, _size);
        _size += size;
    }
    void add(const E &element) {
        ensureCapacityInternal(_size + 1);
        _array[_size++] = element;
    }
    bool contains(const E &element) { return indexOf(element) >= 0; }
    int indexOfInRange(const E &element, int start, int stop) {
        for (int i = start; i < stop; i++)
            if (_array[i] == element)
                return i;
        return -1;
    }
    int indexOf(const E &element) { return indexOfInRange(element, 0, _size); }
    int lastIndexOfInRange(const E &element, int start, int stop) {
        for (int i = stop - 1; i >= start; i--)
            if (_array[i] == element)
                return i;
        return -1;
    }
    int lastIndexOf(const E &element) { return lastIndexOfInRange(element, 0, _size); }
    ArrayList<E> copy() { return ArrayList<E>(*this); }
    E operator[](int index) { return get(index); }
    ArrayList<E> operator+(const E &element) {
        ArrayList<E> result = copy();
        result += element;
        return result;
    }
    ArrayList<E> operator+(const ArrayList<E> &other) {
        ArrayList<E> result = copy();
        result += other;
        return result;
    }
    ArrayList<E> &operator+=(const E &element) {
        add(element);
        return *this;
    }
    ArrayList<E> &operator+=(const ArrayList<E> &other) {
        add(other._array, other._size);
        return *this;
    }
    ArrayList<E> &operator=(const ArrayList<E> &other) {
        if (this != &other) {
            ensureCapacityInternal(other._capacity);
            if (other._size > 0) {
                _array = new E[other._capacity];
                _capacity = other._capacity;
                arraycopy(other._array, _array, other._size);
                _size = other._size;
            }
        }
        return *this;
    }
    E *begin() { return _array; }
    E *end() { return _array + _size; }
    const E *begin() const { return _array; }
    const E *end() const { return _array + _size; }
};


#endif // ARRAYLIST_H
