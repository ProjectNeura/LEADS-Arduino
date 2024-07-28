#ifndef MEMORY_H
#define MEMORY_H


template<typename E>
void arraycopy(const E *const from, E *to, int size, int fromOffset = 0, int toOffset = 0) {
    for (int i = 0; i < size; i++)
        to[i + toOffset] = from[i + fromOffset];
}

template<typename E>
void arraymove(const E *const from, E *to, int size, int fromOffset = 0, int toOffset = 0) {
    arraycopy(from, to, size, fromOffset, toOffset);
    delete from;
}


#endif // MEMORY_H
