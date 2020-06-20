#ifndef POINTERNAMES_LIBRARY_H
#define POINTERNAMES_LIBRARY_H

#include <stdio.h>

struct PointerToNameDictionary *PointerToNameDictionary_new(void* k, const char v[]) {
	struct PointerToNameDictionary* next = NULL;

	const void* key = k;
	const char* value = v;
};

void PointerToNameDictionary_del(struct PointerToNameDictionary* p) {

};

struct PointerToNameNames *PointerToNameNames_new(const char n[]) {
	struct PointerToNameDictionary* next = NULL;

	const char* name = n;
};

const char* getName(void* ptr);

#endif //POINTERNAMES_LIBRARY_H
