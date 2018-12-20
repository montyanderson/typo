#ifndef TYPE
#define TYPE

#include <stdio.h>
#include <stdlib.h>

typedef struct {

} Type;

struct type_header_s {
	int category;
	void (*deconstructor)(Type *);
};

Type *type_create(int category, size_t size, void (*deconstructor)(Type *));
Type *type_destroy(Type *type);

#endif
