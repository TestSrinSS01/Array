#define T void *
#define function(type, name, body) type name(T a) { \
    body\
}
#define consume(name, body) function(void, name, body)
#define supply(name, body) function(T, name, body)
#define predicate(name, body) function(int, name, body)
#define bindArrayFromPrimitive(arrayPrimitive, arr) \
for (int i = 0; i < (arr).length; ++i) {\
    (arr).array[i] = &(arrayPrimitive)[i];\
}                              \
update(arr);
#define bindArrayFromArray(array) update(arr);

typedef struct Array {
    T* array;
    int length;
    void (*forEach)(void (*consumer)(T));
    struct Array (*map)(T (*supplier)(T));
    struct Array (*filter)(int (*predicate)(T));
    int (*indexOf)(T element);
} Array;

Array newArray(int length);
void update(Array);