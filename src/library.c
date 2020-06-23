#include "library.h"

#include <stdio.h>

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

struct Dictionary* pointerToNameDictionary;
struct Names* pointerToNameNames;

const char *getName(void* ptr) {
	if(pointerToNameNames == NULL) defaultPointerToNames();
	if(pointerToNameDictionary == NULL) {
		pointerToNameDictionary = (Dictionary){ptr, pointerToNameNames->name, pointerToNameNames->name};
		pointerToNameNames = pointerToNameNames->next;

		printf("%p\n", pointerToNameNames->next);

		const char* temp = pointerToNameDictionary->value;

		return temp;
	}

	struct Dictionary* dict = pointerToNameDictionary;

	if(dict->key == ptr) return dict->value;
	while(dict->next != NULL) {
		if(dict->key == ptr) return dict->value;
		dict = dict->next;
	}

	dict->next = (Dictionary){ptr, pointerToNameNames->name, NULL};
	pointerToNameNames = pointerToNameNames->next;

	return dict->next->value;
}


void pointerToNames(char* names[]) {
	/*struct Names* next = {" ", NULL};
	pointerToNameNames = next;

	foreach(const char* name, names) {
		next->name = name;
		next = next->next;
	}*/

	struct Names* temp  = {"Hallo", NULL};
	pointerToNameNames = temp;
};

void defaultPointerToNames() {
	pointerToNames((char*[]){
		"Joseph",
		"Test"
	});
}

int main() {
	printf("working!\n");

	defaultPointerToNames();

	printf("%c", pointerToNameNames->name);

	int i = 5;

	//printf("%s\n", getName(&i));

	return 0;
}
