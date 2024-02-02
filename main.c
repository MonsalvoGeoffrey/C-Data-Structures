#include <stdint.h>
#include "lib/vector.c"
#include <stdio.h>

#define literal_ptr(type, value) (&(type){value})

void print_map(void *value, uint32_t index)
{

    printf("The value at index %d is %d\n", index, *(uint16_t *)value);
}

bool remove_50(void *value, uint32_t index)
{
    return *(uint16_t *)value != 50;
}

int main(int argc, char const *argv[])
{
    printf("BEGIN\n");

    Vector *a = vector_init(sizeof(uint16_t));

    printf("INITIALIZED\n");

    for (uint8_t i = 0; i < 10; i++)
    {
        vector_append(a, literal_ptr(uint16_t, 5));
        vector_append(a, literal_ptr(uint16_t, 50));
        vector_append(a, literal_ptr(uint16_t, 500));
        vector_append(a, literal_ptr(uint16_t, 5000));
        vector_insert(a, literal_ptr(uint16_t, 50000), 2);
    }
    vector_remove(a, 48);

    printf("APPENDED\n");

    vector_filter(a, remove_50);  // I wish lambdas were a thing
    vector_foreach(a, print_map); // I wish lambdas were a thing

    vector_free(a);

    printf("END\n");
    return 0;
}
