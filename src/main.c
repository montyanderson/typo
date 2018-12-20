#include <stdio.h>
#include "type.h"
#include "string.h"

void deconstruct(Type *t) {
	printf("deconstruct called\n");
}

int main() {
	Type *type = string_create();

	string_appendc(type, "Hello, ");
	string_appendc(type, "World!");

	type_destroy(type);
}
