#ifndef STRING_H
#define STRING_H

#include "type.h"

struct string_s {
	size_t container;
	size_t length;
	char *array;
};

Type *string_create();
Type *string_expand(Type *type, size_t size);
void string_appendc(Type *type, char *chunk);
char *string_c(Type *type);

#endif
