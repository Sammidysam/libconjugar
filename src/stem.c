#include "stem.h"

#include <string.h>

#include "verb.h"

/* Includes from other header files. */
/* verb.h */
// #include <stdbool.h>

/*
 * Retrieves the ending of string verb.
 * If it has a valid ending, the function will return that ending.
 * If the ending is not valid, the function will return "".
 *
 * verb.c->cjr_is_verb(char *verb) calls this function, so
 * do not call that function within this function!
 */
char *cjr_get_ending(char *verb)
{
	return verb;
}

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
	
	return verb;
}
