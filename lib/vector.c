#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>



#ifndef KELPIE_VECTOR
#define KELPIE_VECTOR

struct Vector
{
    uint32_t size;
    size_t type_size;
    size_t true_size;
    void *data;
} typedef Vector;

Vector *vector_init(size_t type_size)
{
    Vector *new_vector = malloc(sizeof(Vector));
    new_vector->true_size = 8 * type_size;
    new_vector->size = 0;
    new_vector->type_size = type_size;

    new_vector->data = malloc(8 * type_size);

    return new_vector;
}

uint32_t vector_length(Vector *self)
{
    return self->size;
}

void *vector_get(Vector *self, uint32_t index)
{
    if (index > self->size)
    {
        fprintf(stderr, "Error: Index %d out of bounds.\n", index);
        abort();
    }
    return ((uint8_t *)self->data) + (index * self->type_size);
}

void vector_resize(Vector *self, size_t target)
{
    self->true_size = target;
    self->data = realloc(self->data, target);
    // TODO: Error Management
}

void vector_insert(Vector *restrict self, void *restrict value, uint32_t index)
{
    if (index >= self->size)
    {
        fprintf(stderr, "Error: Index %d out of bounds.\n", index);
        abort();
    }
    if (self->size * self->type_size == self->true_size)
    {
        vector_resize(self, self->true_size * 2);
    }
    memmove(
        (uint8_t *)(self->data) + ((index + 1) * self->type_size),
        ((uint8_t *)self->data) + (index * self->type_size),
        (self->size - index) * self->type_size);
    memcpy((uint8_t *)(self->data) + (index * self->type_size), value, self->type_size);
    self->size++;
}

void vector_append(Vector *restrict self, void *restrict value)
{
    if (self->size * self->type_size == self->true_size)
    {
        vector_resize(self, self->true_size * 2);
    }
    const uint32_t index = self->size;
    memcpy((uint8_t *)(self->data) + (index * self->type_size), value, self->type_size);
    self->size++;
}

void vector_free(Vector *self)
{
    free(self->data);
    free(self);
}

void vector_free_all(Vector *self)
{
    for (uint32_t index; index < self->size; index++)
    {
        free(vector_get(self, index));
    }
    free(self->data);
    free(self);
}

void vector_foreach(Vector *self, void (*func)(void *, uint32_t))
{
    for (uint32_t index; index < self->size; index++)
    {
        func(vector_get(self, index), index);
    }
}

void vector_remove(Vector *self, uint32_t index);
void vector_filter(Vector *self, bool (*func)(void *, uint32_t))
{
    for (uint32_t index; index < self->size; index++)
    {
        if (func(vector_get(self, index), index) == false)
        {
            vector_remove(self, index);
            index--;
        }
    }
}

void vector_remove(Vector *self, uint32_t index)
{
    memmove(
        ((uint8_t *)self->data) + (index * self->type_size),
        (uint8_t *)(self->data) + ((index + 1) * self->type_size),
        (self->size - index) * self->type_size);
    self->size--;
}

#endif