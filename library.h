#ifndef POINTERNAMES_LIBRARY_H
#define POINTERNAMES_LIBRARY_H

#include <stdio.h>

struct PointerToNameDictionary *PointerToNameDictionary(void* k, char v[10]);

struct PointerToNameNames *PointerToNameNames(char n[10]);

char* getName(void* ptr);

void pointerToNames();

#endif //POINTERNAMES_LIBRARY_H
