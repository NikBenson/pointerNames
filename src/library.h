#ifndef POINTERNAMES_LIBRARY_H
#define POINTERNAMES_LIBRARY_H

#include <stdio.h>

typedef struct PointerToNameDictionary *Dictionary;

typedef struct Names {
	const char* name;
	struct PointerToNameDictionary* next;


};

typedef struct Dictionary {
	void* key;
	const char* value;

	struct Dictionary* next;
};

const char* getName(void* ptr);

void pointerToNames(char* names[]);
void defaultPointerToNames();




#endif //POINTERNAMES_LIBRARY_H
