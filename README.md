made this just for fun since i'm learning C ;-;
#Array in c
implemented array using structure in c  
```c
struct Array {
    void** array;
    int length;
    void (*forEach)(void (*consumer)(void*));
    struct Array (*map)(void* (*supplier)(void*));
    struct Array (*filter)(int (*predicate)(void*));
    int (*indexOf)(void* element);
}
```
##create a new Array
lets create an array of length 4  
```c
Array foo = newArray(4);
```
##initialize an Array
you need to create the primitive array first, for example:  
```c
int bar[] = { 1, 2, 3, 4 };
```
or
```c
char* bar[] = { "Foo", "Bar" };
```
then use the macro `bindArrayFromPrimitive(arrayPrimitive, arr)` to initialize the Array  
```c
bindArrayFromPrimitive(bar, foo);
```
##initialize Array from existing Array
first copy the array then use the macro `bindArrayFromArray(array)`
```c
Array copy = foo;
bindArrayFromArray(copy)
```
###how to use `filter`, `forEach`, `map`, `indexOf`:
you can define your own functions for `consumer`, `predicate` and `supplier`  
or you can use the macros `consume(functionname, body)`, `supply(functionname, body)`, `predicate(functionname, body)`
```c
Array foo = newArray(4);
int bar[] = { 1, 2, 3, 4 };
bindArrayFromPrimitive(bar, foo);
foo.filter(/* pointer to the predicate function */); // int predicate(void* a);
foo.forEach(/* pointer to the consumer function */); // void consumer(void* a);
foo.map(/* pointer to the supplier function */); // void* supplier(void* a);
foo.indexOf(/* pointer to the element */); // int indexOf(void* element);
```
