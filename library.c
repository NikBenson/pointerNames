#include "library.h"

#include <stdio.h>

struct PointerToNameDictionary* pointerToNameDictionary = NULL;
struct PointerToNameNames* pointerToNameNames = {"test"};

const char *getName(void* ptr) {
	if(pointerToNameDictionary == NULL) {
		pointerToNameDictionary = PointerToNameDictionary_new(ptr, pointerToNameNames->name);
		pointerToNameNames = pointerToNameNames->next;
		return pointerToNameDictionary->value;
	}

	struct PointerToNameDictionary* dict = pointerToNameDictionary;

	if(dict->key == ptr) return dict->value;
	while(dict->next != NULL) {
		if(dict->key == ptr) return dict->value;
		dict = dict->next;
	}

	dict->next = PointerToNameDictionary_new(ptr, pointerToNameNames->name);
	pointerToNameNames = pointerToNameNames->next;

	return dict->next->value;
}
