#include <stdint.h>
#include "lib/vector.c"
#include <stdio.h>

#define literal_ptr(type, value) (&(type){value})

void print_map(void *value, uint32_t index)
{

    printf("The value at index %d is %d\n", index, *(uint16_t *)value);
}

int main(int argc, char const *argv[])
{
    printf("BEGIN\n");

    Vector *a = vector_init(sizeof(uint16_t));

    printf("INITIALIZED\n");

    vector_append(a, literal_ptr(uint16_t, 5));
    vector_append(a, literal_ptr(uint16_t, 50));
    vector_append(a, literal_ptr(uint16_t, 500));
    vector_append(a, literal_ptr(uint16_t, 5000));
    vector_insert(a, literal_ptr(uint16_t, 50000), 2);
    vector_append(a, literal_ptr(uint16_t, 5));
    vector_append(a, literal_ptr(uint16_t, 50));
    vector_append(a, literal_ptr(uint16_t, 500));
    vector_append(a, literal_ptr(uint16_t, 5000));
    vector_insert(a, literal_ptr(uint16_t, 50000), 2);
    vector_append(a, literal_ptr(uint16_t, 5));
    vector_append(a, literal_ptr(uint16_t, 50));
    vector_append(a, literal_ptr(uint16_t, 500));
    vector_append(a, literal_ptr(uint16_t, 5000));
    vector_insert(a, literal_ptr(uint16_t, 50000), 2);
    vector_append(a, literal_ptr(uint16_t, 5));
    vector_append(a, literal_ptr(uint16_t, 50));
    vector_append(a, literal_ptr(uint16_t, 500));
    vector_append(a, literal_ptr(uint16_t, 5000));
    vector_insert(a, literal_ptr(uint16_t, 50000), 2);
    vector_append(a, literal_ptr(uint16_t, 5));
    vector_append(a, literal_ptr(uint16_t, 50));
    vector_append(a, literal_ptr(uint16_t, 500));
    vector_append(a, literal_ptr(uint16_t, 5000));
    vector_insert(a, literal_ptr(uint16_t, 50000), 2);

    printf("APPENDED\n");

    // printf("Index 0: %d\n", *(uint16_t *)vector_get(a, 0));
    // printf("Index 1: %d\n", *(uint16_t *)vector_get(a, 1));
    // printf("Index 2: %d\n", *(uint16_t *)vector_get(a, 2));
    // printf("Index 3: %d\n", *(uint16_t *)vector_get(a, 3));
    // printf("Index 4: %d\n", *(uint16_t *)vector_get(a, 4));
    vector_foreach(a, print_map); // I wish lambdas were a thing

    printf("END\n");
    return 0;
}
