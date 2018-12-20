#include "type.h"

Type *type_create(int category, size_t size, void (*deconstructor)(Type *)) {
	struct type_header_s *header = malloc(sizeof(struct type_header_s) + size);

	header->category = category;
	header->deconstructor = deconstructor;

	Type *type = (Type *) (((char *) header) + sizeof(struct type_header_s));
}

Type *type_destroy(Type *type) {
	struct type_header_s *header = (struct type_header_s *) (((char *) type) - sizeof(struct type_header_s));

	if(header->deconstructor != NULL) {
		header->deconstructor(type);
	}

	free(header);
}
