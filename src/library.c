#include "library.h"

#include <stdio.h>

/*#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

typedef struct PointerToNameNames *PointerToNameNames(char n[10]) {
	struct PointerToNameDictionary* next = NULL;

	char* name = n;
};

typedef struct PointerToNameDictionary *PointerToNameDictionary(void *k, char v[10]) {
	struct PointerToNameDictionary* next = NULL;

	void* key = k;
	char* value = v;
};


struct PointerToNameDictionary* pointerToNameDictionary;
struct PointerToNameNames* pointerToNameNames;

char *getName(void* ptr) {
	if(pointerToNameNames == NULL) defaultPointerToNames();
	if(pointerToNameDictionary == NULL) {
		pointerToNameDictionary = PointerToNameDictionary(ptr, pointerToNameNames->name);
		pointerToNameNames = pointerToNameNames->next;
		return pointerToNameDictionary->value;
	}

	struct PointerToNameDictionary* dict = pointerToNameDictionary;

	if(dict->key == ptr) return dict->value;
	while(dict->next != NULL) {
		if(dict->key == ptr) return dict->value;
		dict = dict->next;
	}

	dict->next = PointerToNameDictionary(ptr, pointerToNameNames->name);
	pointerToNameNames = pointerToNameNames->next;

	return dict->next->value;
}


void pointerToNames(char names[][10]) {
	struct PointerToNameNames* next = {NULL, NULL};
	pointerToNameNames = next;
	foreach(char* name, names) {
		next->name = (PointerToNameNames){{NULL, NULL}, name};
		next = next->next;
	}
	next->next = NULL;
};

void defaultPointerToNames() {
	pointerToNames((char[][10]){
		"Angelo",
		"Chris",
		"Skyla",
		"James",
		"Karlos",
		"Hans",
		"Klaus",
		"Linus",
		"Frank",
		"Wolfgang",
		"Paula",
		"Kleopatra",
		"Nikola",
		"Gustav",
		"Julius",
		"Alexander",
		"Nik",
		"Fyn",
		"Markus",
		"Elisabeth",
		"Alice",
		"Ferdinant",
		"Napoleon",
		"Thomas",
		"Torben",
		"Willhelm",
		"Vincent",
		"Markus",
		"Helmut",
		"Otto",
		"Franz",
		"Cleo",
		"Sebastian",
		"Olliver",
		"Diana",
		"Maria",
		"Herkules",
		"Bilbo",
		"Merlin",
		"Frodo",
		"Smaug",
		"Shelob",
		"Gandalf",
		"Dumbledore",
		"Samwise",
		"Peregrin",
		"Meriadoc",
		"Sauron",
		"Saroman",
		"Hermes",
		"Loki",
		"Zeus",
		"Heracles",
		"Minos",
		"Gilgamech",
		"Jesus",
		"Charles",
		"Logan",
		"Anakin",
		"Sheev",
		"Padme",
		"Yoda",
		"Chewbacca",
		"Maurice",
		"Mario",
		"Koopa",
		"Kamek",
		"Bowser",
		"Yoshi",
		"Gumba",
		"Toad",
		"Victor",
		"Tony",
		"Peach",
		"Daisy",
		"Amy",
		"Rosalina",
		"Hornet",
		"Toadette",
		"Fawfull",
		"Ray",
		"Kylo",
		"Shrek",
		"Fiona",
		"Hera",
		"Rosa",
		"Ruto",
		"Ganondorf",
		"Zelda",
		"Link",
		"Mipha",
		"Pauline",
		"Zote",
		"Grimm",
		"Greta",
		"Hilda",
		"Cynthia",
		"Red",
		"Blue",
		"Pennywise",
		"Phineas",
		"Ferb",
		"Candace",
		"Isabella",
		"Kirby",
		"Dedede",
		"Marx",
		"Snatcher",
		"DJGrooves",
		"Louis",
		"Marge",
	});
}*/

int main() {
	printf("working!\n");

	return 0;
}
