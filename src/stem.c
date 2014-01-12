#include "stem.h"

#include <stdlib.h>
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

	/* verb is not modifiable, so we need a copy to modify. */
	char *verb_return = malloc(sizeof(char) * verb_length);
	strcpy(verb_return, verb);

	/* TODO: split into own function? */
	/* Remove last chars_to_delete characters from verb. */
	for (size_t i = verb_length - 1; i >= verb_length - chars_to_delete; i--) {
		verb_return[i] = '\0';
	}
	
	return chars_to_delete > 0 ? verb_return : "";
}
