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

__unused const char *getName(void* ptr) {
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


void pointerToNames(const char names[][10]) {
	struct Names* next = {" ", NULL};
	pointerToNameNames = next;

	printf("%d\n", sizeof(names));

	foreach(const char* name, names) {
		next->name = name;
		next = next->next;
	}
};

void defaultPointerToNames() {
	pointerToNames( (const char [][10]) {
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
}

int main() {
	printf("working!\n");

	defaultPointerToNames();

	printf("%s\n", pointerToNameNames->name);

	int i = 5;

	//printf("%s\n", getName(&i));

	return 0;
}
