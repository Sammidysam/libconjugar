#include "stem.h"

#include <stdlib.h>
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
	/* Max verb ending length is 4, so 8 is safe. */
	char *ending = malloc(8 * sizeof(char));
	char *last_two_characters = &verb[(strlen(verb) > 2) ? (strlen(verb) - 2) : 0];

	/* If ending is se, then we need to get more information. */
	if (strcmp(last_two_characters, "se") == 0) {
		/*
		 * We need the last four characters to determine
		 * what kind of verb ending in "se" it is.
		 */
		char *last_four_characters = &verb[(strlen(verb) > 4) ? (strlen(verb) - 4) : 0];

		if (strcmp(last_four_characters, "arse") == 0
		    || strcmp(last_four_characters, "erse") == 0
		    || strcmp(last_four_characters, "irse") == 0)
			ending = last_four_characters;
	} else {
		if (strcmp(last_two_characters, "ar") == 0
		    || strcmp(last_two_characters, "er") == 0
		    || strcmp(last_two_characters, "ir") == 0)
			ending = last_two_characters;
	}
	
	return strlen(ending) == 0 ? "" : ending;
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
	
	return chars_to_delete > 0 ? verb : "";
}
