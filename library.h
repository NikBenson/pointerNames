#ifndef POINTERNAMES_LIBRARY_H
#define POINTERNAMES_LIBRARY_H

#include <stdio.h>

struct PointerToNameDictionary *PointerToNameDictionary(void* k, const char v[]) {
	struct PointerToNameDictionary* next = NULL;

	const void* key = k;
	const char* value = v;
};

struct PointerToNameNames *PointerToNameNames(const char n[]) {
	struct PointerToNameDictionary* next = NULL;

	const char* name = n;
};

const char* getName(void* ptr);

#endif //POINTERNAMES_LIBRARY_H
