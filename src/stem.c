#include "stem.h"

#include <string.h>

#include "verb.h"

/* Includes from other header files. */
/* verb.h */
// #include <stdbool.h>

/*
 * Retrieves the stem of string verb.
 * The ending, retrieved from cjr_get_ending,
 * will be removed from the end of verb.
 */
char *cjr_get_stem(char *verb)
{
	size_t verb_length = strlen(verb);
	size_t chars_to_delete = strlen(cjr_get_ending(verb));

	/* TODO: split into own function? */
	/* Remove last chars_to_delete characters from verb. */
	for (size_t i = verb_length; i >= verb_length - chars_to_delete; i--) {
		verb[i] = '\0';
	}
	
	return chars_to_delete > 0 ? verb : "";
}
