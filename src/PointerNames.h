#ifndef POINTERNAMES_POINTERNAMES_H
#define POINTERNAMES_POINTERNAMES_H

#include <malloc.h>

#define NULL (void*)0

/**
 * @struct PointerNamesNamesList in linked list
 * @var string name value of this node
 * @var PointerNamesNamesList next child node of linked list
 */
struct PointerNamesNamesList {
	const char* name;

	struct PointerNamesNamesList* next;
};

/**
 * @struct PointerToNamesDictionary of pointers to names in linked list
 * @var pointer key linked by value
 * @var string value linked by key
 * @var PointerToNamesDictionary next child node of linked list
 */
struct PointerToNamesDictionary {
	void* key;
	const char* value;

	struct PointerToNamesDictionary* next;
};

/**
 * Returns the value according to PointerToNamesDictionary using ptr.
 * Updates PointerToNamesDictionary if necessary.
 * @param pointer ptr
 * @return string name
 */
const char* getPointerName(void*);

/**
 * Initialises pointerNames environment with custom names.
 * @param string[] names
 */
void setPointerToNamesList(const char[][16], int length);

/**
 * Initialises pointerNames environment with default names.
 */
void defaultPointerToNames();



struct PointerToNamesDictionary* pointerToNamesDictionary;
struct PointerNamesNamesList* pointerToNameNames;

/**
 * Returns the value according to PointerToNamesDictionary using ptr.
 * Updates PointerToNamesDictionary if necessary.
 * @param pointer ptr
 * @return string name
 */
const char *getPointerName(void* ptr) {
	//first entry
	if(pointerToNamesDictionary == NULL) {
		//make sure that there is  always a next name
		if(pointerToNameNames == NULL) {
			defaultPointerToNames();
		}

		//use and remove name, init PointerToNamesDictionary
		pointerToNamesDictionary = (PointerToNamesDictionary*) malloc(sizeof(struct PointerToNamesDictionary));
		pointerToNamesDictionary->key = ptr;
		pointerToNamesDictionary->value = pointerToNameNames->name;
		pointerToNameNames = pointerToNameNames->next;

		return pointerToNamesDictionary->value;
	}

	//search for key in PointerToNamesDictionary
	struct PointerToNamesDictionary* dict = pointerToNamesDictionary;

	do {
		if(dict->key == ptr) return dict->value;
		dict = dict->next;
	} while(dict != NULL);

	//make sure that there is  always a next name
	if(pointerToNameNames == NULL) {
		defaultPointerToNames();
	}

	//use and remove next name
	struct PointerToNamesDictionary* temp = pointerToNamesDictionary;
	pointerToNamesDictionary = (PointerToNamesDictionary*) malloc(sizeof(struct PointerToNamesDictionary));
	pointerToNamesDictionary->key = ptr;
	pointerToNamesDictionary->value = pointerToNameNames->name;
	pointerToNameNames = pointerToNameNames->next;
	pointerToNamesDictionary->next = temp;

	return pointerToNamesDictionary->value;
}

/**
 * Initialises pointerNames environment with custom names.
 * @param string[] names
 */
void setPointerToNamesList(const char names[][16] = (char[][16]) {
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
}, int length = 110) {
	pointerToNameNames = (PointerNamesNamesList*) malloc(sizeof(struct PointerNamesNamesList));
	pointerToNameNames->name = names[0];
	struct PointerNamesNamesList* name = pointerToNameNames;

	for(unsigned int i = 1; i < length; i++) {
		name->next = (PointerNamesNamesList*) malloc(sizeof(struct PointerNamesNamesList));
		name->next->name = names[i];
		name = name->next;
	}
}

#endif //POINTERNAMES_POINTERNAMES_H
