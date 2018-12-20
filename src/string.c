#include <string.h>
#include "string.h"

void string_destroy(Type *type) {
	struct string_s *string = (struct string_s *) type;

	free(string->array);
}

Type *string_create() {
	Type *type = type_create(100, sizeof(struct string_s), string_destroy);

	struct string_s *string = (struct string_s *) type;

	string->container = 8;
	string->length = 0;
	string->array = calloc(string->container, 1);
}

Type *string_expand(Type *type, size_t size) {
	struct string_s *string = (struct string_s *) type;

	while(string->container <= size) {
		string->container *= 2;
	}

	string->array = realloc(string->array, string->container);
}

void string_appendc(Type *type, char *chunk) {
	struct string_s *string = (struct string_s *) type;

	size_t chunk_size = strlen(chunk);

	string_expand(type, string->length + chunk_size);

	memcpy(string->array + string->length, chunk, chunk_size);
	string->length += chunk_size;

	string->array[string->length] = 0x00;
}

char *string_c(Type *type) {
	struct string_s *string = (struct string_s *) type;

	return string->array;
}
