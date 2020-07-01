#include "library.h"

#include <stdio.h>
#include <malloc.h>

#define NULL (void*)0


struct Dictionary* pointerToNamesDictionary;
struct Names* pointerToNameNames;

/**
 * Returns the value according to Dictionary using ptr.
 * Updates Dictionary if necessary.
 * @param pointer ptr
 * @return string name
 */
const char *getName(void* ptr) {
	//first entry
	if(pointerToNamesDictionary == NULL) {
		//make sure that there is  always a next name
		if(pointerToNameNames == NULL) {
			printf("%s\n%s\n", "out of names!", "using default names, maybe not the first time.");
			defaultPointerToNames();
		}

		//use and remove name, init Dictionary
		pointerToNamesDictionary = malloc(sizeof(struct Dictionary));
		pointerToNamesDictionary->key = ptr;
		pointerToNamesDictionary->value = pointerToNameNames->name;
		pointerToNameNames = pointerToNameNames->next;

		return pointerToNamesDictionary->value;
	}

	//search for key in Dictionary
	struct Dictionary* dict = pointerToNamesDictionary;

	do {
		if(dict->key == ptr) return dict->value;
		dict = dict->next;
	} while(dict != NULL);

	//make sure that there is  always a next name
	if(pointerToNameNames == NULL) {
		printf("%s\n%s\n", "out of names!", "using default names, maybe not the first time.");
		defaultPointerToNames();
	}

	//use and remove next name
	struct Dictionary* temp = pointerToNamesDictionary;
	pointerToNamesDictionary = malloc(sizeof(struct Dictionary));
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
void pointerToNames(const char names[][10], int length) {
	pointerToNameNames = &(struct Names){.name = names[0], .next = NULL};
	struct Names* name = pointerToNameNames;

	for(unsigned int i = 1; i < length; i++) {
		name->next = malloc(sizeof(struct Names));
		name->next->name = names[i];
		name = name->next;
	}
}

/**
 * Initialises pointerNames environment with default names.
 */
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
	}, 110);
}
