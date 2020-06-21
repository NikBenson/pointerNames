#ifndef POINTERNAMES_LIBRARY_H
#define POINTERNAMES_LIBRARY_H

#include <stdio.h>

struct PointerToNameDictionary *PointerToNameDictionary(void* k, char v[]);

struct PointerToNameNames *PointerToNameNames(char n[]);

char* getName(void* ptr);

void pointerToNames();

#endif //POINTERNAMES_LIBRARY_H
