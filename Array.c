#include "./Array.h"
#include <stdlib.h>

Array array;

void forEach(void (*consumer)(T)) {
    for (int i = 0; i < array.length; ++i)
        consumer(array.array[i]);
}

int indexOf(T element) {
    for (int i = 0; i < array.length; ++i)
        if (array.array[i] == element) return i;
    return -1;
}

Array filter(int (*predicat)(T)) {
    int length = 0;
    for (int i = 0; i < array.length; ++i)
        if (predicat(array.array[i])) length++;
    Array filteredArray = newArray(length);
    int k = 0;
    for (int i = 0; i < array.length; ++i) {
        T element = array.array[i];
        if (predicat(element)) filteredArray.array[k++] = element;
    }
    return array = filteredArray;
}

Array map(T (*supplier)(T)) {
    Array new = newArray(array.length);
    for (int i = 0; i < new.length; ++i)
        new.array[i] = supplier(array.array[i]);
    return new;
}

void update(Array arr) {
    array = arr;
}

Array newArray(int size) {
    Array arr = {
            .array = malloc(size * sizeof(T)),
            .length = size,
            .forEach = &forEach,
            .map = &map,
            .filter = &filter,
            .indexOf = &indexOf
    };
    return arr;
}