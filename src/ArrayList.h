#ifndef ARRAYLIST_H
#define ARRAYLIST_H


#include "Arduino.h"

template<typename E>
class ArrayList {
private:
    size_t _size, _capacity;
    E *_array;
    void grow(size_t minCapacity) {
        size_t newCapacity = _capacity + (_capacity >> 1);
        if (newCapacity < minCapacity)
            newCapacity = minCapacity;
        E *newArray = new E[newCapacity];
        memmove(newArray, _array, _size * sizeof(E));
        delete[] _array;
        _array = newArray;
        _capacity = newCapacity;
    }
    void ensureExplicitCapacity(size_t minCapacity) {
        if (minCapacity > _capacity)
            grow(minCapacity);
    }
    void ensureCapacityInternal(size_t minCapacity) { ensureExplicitCapacity(max(10, minCapacity)); }
    void add(E *elements, size_t size) {
        ensureCapacityInternal(_size + size);
        memcpy(_array + _size, elements, size * sizeof(E));
    }

public:
    explicit ArrayList(size_t initialCapacity = 10) :
        _size(0), _capacity(initialCapacity), _array(new E[initialCapacity]) {}
    explicit ArrayList(E const *const initialArray, size_t size) : _size(0), _capacity(size), _array(new E[size]) {
        memcpy(_array, initialArray, size * sizeof(E));
    }
    ~ArrayList() { delete[] _array; }
    int size() { return _size; }
    E const *toArray() { return _array; }
    void set(int index, E element) { _array[index] = element; }
    E get(int index) { return _array[index]; }
    void clear() {
        delete[] _array;
        _array = new E[0];
        _size = _capacity = 0;
    }
    void add(E element) {
        ensureCapacityInternal(_size + 1);
        _array[_size++] = element;
    }
    ArrayList<E> add(ArrayList<E> other) {
        ArrayList<E> result = copy();
        result.add(other._array, other._size);
        return result;
    }
    bool contains(E element) { return indexOf(element) >= 0; }
    int indexOfInRange(E element, int start, int stop) {
        for (int i = start; i < stop; i++)
            if (_array[i] == element)
                return i;
        return -1;
    }
    int indexOf(E element) { return indexOfInRange(element, 0, _size); }
    int lastIndexOfInRange(E element, int start, int stop) {
        for (int i = stop - 1; i >= start; i--)
            if (_array[i] == element)
                return i;
        return -1;
    }
    int lastIndexOf(E element) { return lastIndexOfInRange(element, 0, _size); }
    ArrayList<E> copy() { return ArrayList<E>(_array); }
};


#endif // ARRAYLIST_H
