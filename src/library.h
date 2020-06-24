#ifndef POINTERNAMES_LIBRARY_H
#define POINTERNAMES_LIBRARY_H

/**
 * @struct Names in linked list
 * @var string name value of this node
 * @var Names next child node of linked list
 */
typedef struct Names {
	const char* name;

	struct Names* next;
};

/**
 * @struct Dictionary of pointers to names in linked list
 * @var pointer key linked by value
 * @var string value linked by key
 * @var Dictionary next child node of linked list
 */
typedef struct Dictionary {
	void* key;
	const char* value;

	struct Dictionary* next;
};

/**
 * Returns the value according to Dictionary using ptr.
 * Updates Dictionary if necessary.
 * @param pointer ptr
 * @return string name
 */
const char* getName(void*);

/**
 * Initialises pointerNames environment with custom names.
 * @param string[] names
 */
void pointerToNames(const char [][10], int length);

/**
 * Initialises pointerNames environment with default names.
 */
void defaultPointerToNames();


#endif //POINTERNAMES_LIBRARY_H
